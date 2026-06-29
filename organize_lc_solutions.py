"""
organize_lc_solutions.py

Run this INSIDE your local lc-solutions repo folder (C:\Projects\lc-solutions).

What it does:
1. Scans all solution files anywhere in the repo (root + topic subfolders).
2. Looks up each LeetCode problem number's title, difficulty, and topic tags
   via LeetCode's public GraphQL API.
3. Reorganizes files into topic-based folders.
4. Generates a README.md with a full table: # | Name | Difficulty | Topic | Language | Link

Requirements:
    pip install requests --break-system-packages

Usage:
    python organize_lc_solutions.py            # dry run
    python organize_lc_solutions.py --apply    # actually moves files into folders
"""

import os
import re
import sys
import time
import json
import shutil
from pathlib import Path

try:
    import requests
except ImportError:
    print("Missing dependency. Run: pip install requests --break-system-packages")
    sys.exit(1)

ROOT = Path(__file__).resolve().parent
LANG_EXT = {
    ".cpp": "cpp",
    ".py": "python",
    ".js": "javascript",
    ".java": "java",
    ".sql": "sql",
}

LEETCODE_GRAPHQL = "https://leetcode.com/graphql"

QUERY = """
query questionTitle($titleSlug: String) {
  question(titleSlug: $titleSlug) {
    questionFrontendId
    title
    titleSlug
    difficulty
    topicTags {
      name
    }
  }
}
"""

PROBLEMS_LIST_URL = "https://leetcode.com/api/problems/all/"


def fetch_problem_index():
    print("Fetching LeetCode problem index (one-time)...")
    resp = requests.get(PROBLEMS_LIST_URL, timeout=15)
    resp.raise_for_status()
    data = resp.json()
    index = {}
    for item in data.get("stat_status_pairs", []):
        stat = item["stat"]
        qid = str(stat["frontend_question_id"])
        index[qid] = {
            "slug": stat["question__title_slug"],
            "title": stat["question__title"],
        }
    return index


def fetch_problem_detail(slug):
    payload = {"query": QUERY, "variables": {"titleSlug": slug}}
    resp = requests.post(LEETCODE_GRAPHQL, json=payload, timeout=15)
    resp.raise_for_status()
    data = resp.json()
    q = data.get("data", {}).get("question")
    return q


def slugify(text):
    text = text.lower()
    text = re.sub(r"[^a-z0-9]+", "-", text)
    return text.strip("-")


def primary_topic_folder(topic_tags):
    if not topic_tags:
        return "uncategorized"
    preferred_order = [
        "Dynamic Programming", "Graph", "Tree", "Binary Search",
        "Greedy", "Backtracking", "Database", "Array", "Hash Table",
        "String", "Two Pointers", "Sliding Window", "Stack", "Heap (Priority Queue)",
        "Linked List", "Math", "Bit Manipulation", "Sorting",
    ]
    names = [t["name"] for t in topic_tags]
    for p in preferred_order:
        if p in names:
            return slugify(p)
    return slugify(names[0])


def main():
    apply_moves = "--apply" in sys.argv

    files = []
    for f in ROOT.rglob("*"):
        if f.is_file() and f.suffix in LANG_EXT:
            m = re.match(r"^(\d+)", f.stem)
            if m:
                files.append((int(m.group(1)), f))

    if not files:
        print("No numeric-prefixed solution files found in this folder.")
        return

    files.sort(key=lambda x: x[0])
    print(f"Found {len(files)} solution files.\n")

    index = fetch_problem_index()

    rows = []
    manual_entries = []
    moves = []

    for num, path in files:
        qid = str(num)
        info = index.get(qid)
        lang = LANG_EXT[path.suffix]

        if not info:
            manual_entries.append((num, path.name, lang))
            rows.append({
                "num": num, "name": "(needs manual entry)", "difficulty": "?",
                "topic": "uncategorized", "lang": lang, "file": path.name,
            })
            continue

        try:
            detail = fetch_problem_detail(info["slug"])
            time.sleep(0.3)
        except Exception as e:
            print(f"  [warn] lookup failed for #{num}: {e}")
            manual_entries.append((num, path.name, lang))
            rows.append({
                "num": num, "name": info["title"], "difficulty": "?",
                "topic": "uncategorized", "lang": lang, "file": path.name,
            })
            continue

        if not detail:
            manual_entries.append((num, path.name, lang))
            rows.append({
                "num": num, "name": info["title"], "difficulty": "?",
                "topic": "uncategorized", "lang": lang, "file": path.name,
            })
            continue

        title = detail["title"]
        difficulty = detail["difficulty"]
        topic_folder = primary_topic_folder(detail["topicTags"])
        new_name = f"{num}-{slugify(title)}{path.suffix}"
        new_rel_path = f"{topic_folder}/{new_name}"

        rows.append({
            "num": num, "name": title, "difficulty": difficulty,
            "topic": topic_folder, "lang": lang, "file": new_rel_path,
        })
        dest_path = ROOT / topic_folder / new_name
        if path.resolve() != dest_path.resolve():
            moves.append((path, dest_path))

        print(f"  #{num:<5} {title:<40} [{difficulty:<6}] -> {new_rel_path}")

    write_readme(rows)

    if manual_entries:
        print(f"\n{len(manual_entries)} problems need manual entry (lookup failed):")
        for num, fname, lang in manual_entries:
            print(f"  #{num} - {fname}")

    if apply_moves:
        print(f"\nApplying {len(moves)} file moves...")
        for src, dst in moves:
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.move(str(src), str(dst))
        print("Done. Files reorganized into topic folders.")
    else:
        print(f"\nDry run only - {len(moves)} files would be moved.")
        print("Re-run with --apply to actually move them into topic folders.")
        print("README.md has been written either way.")


def write_readme(rows):
    by_lang_count = {}
    by_diff_count = {}
    for r in rows:
        by_lang_count[r["lang"]] = by_lang_count.get(r["lang"], 0) + 1
        by_diff_count[r["difficulty"]] = by_diff_count.get(r["difficulty"], 0) + 1

    lines = []
    lines.append("# LeetCode Solutions & DSA Practice\n")
    lines.append(
        f"A collection of **{len(rows)} solved problems** from LeetCode, "
        "covering data structures, algorithms, and SQL database problems.\n"
    )
    lines.append("## Stats\n")
    lang_line = " | ".join(f"{k.upper()}: {v}" for k, v in sorted(by_lang_count.items()))
    diff_line = " | ".join(f"{k}: {v}" for k, v in sorted(by_diff_count.items()) if k != "?")
    lines.append(f"- **By language:** {lang_line}")
    lines.append(f"- **By difficulty:** {diff_line}\n")

    lines.append("## Problems\n")
    lines.append("| # | Problem | Difficulty | Topic | Language | File |")
    lines.append("|---|---------|------------|-------|----------|------|")
    for r in sorted(rows, key=lambda x: x["num"]):
        link = f"https://leetcode.com/problems/{slugify(r['name'])}/" if r["name"] != "(needs manual entry)" else ""
        name_cell = f"[{r['name']}]({link})" if link else r["name"]
        lines.append(
            f"| {r['num']} | {name_cell} | {r['difficulty']} | {r['topic']} | "
            f"{r['lang']} | `{r['file']}` |"
        )

    lines.append("\n---")
    lines.append("_README auto-generated from LeetCode's public API. "
                  "Re-run `organize_lc_solutions.py` after adding new solutions._")

    (ROOT / "README.md").write_text("\n".join(lines), encoding="utf-8")
    print(f"\nREADME.md written with {len(rows)} entries.")


if __name__ == "__main__":
    main()
