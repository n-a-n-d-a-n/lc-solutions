"""
fix_2356.py

Retries the LeetCode API lookup for problem #2356 (it timed out during the
original run) and patches it into the existing README.md table, plus moves
the file into the correct topic folder - fully automated, no manual typing.

Run this INSIDE C:\Projects\lc-solutions (same folder as 2356.sql).

Usage:
    python fix_2356.py
"""

import re
import time
import shutil
from pathlib import Path

import requests

ROOT = Path(__file__).resolve().parent
NUM = 2356

LEETCODE_GRAPHQL = "https://leetcode.com/graphql"
PROBLEMS_LIST_URL = "https://leetcode.com/api/problems/all/"

QUERY = """
query questionTitle($titleSlug: String) {
  question(titleSlug: $titleSlug) {
    title
    difficulty
    topicTags { name }
  }
}
"""

PREFERRED_ORDER = [
    "Dynamic Programming", "Graph", "Tree", "Binary Search",
    "Greedy", "Backtracking", "Database", "Array", "Hash Table",
    "String", "Two Pointers", "Sliding Window", "Stack", "Heap (Priority Queue)",
    "Linked List", "Math", "Bit Manipulation", "Sorting",
]


def slugify(text):
    text = text.lower()
    text = re.sub(r"[^a-z0-9]+", "-", text)
    return text.strip("-")


def topic_folder(tags):
    names = [t["name"] for t in tags]
    for p in PREFERRED_ORDER:
        if p in names:
            return slugify(p)
    return slugify(names[0]) if names else "uncategorized"


def fetch_with_retry(slug, attempts=4):
    for i in range(attempts):
        try:
            resp = requests.post(
                LEETCODE_GRAPHQL,
                json={"query": QUERY, "variables": {"titleSlug": slug}},
                timeout=30,
            )
            resp.raise_for_status()
            data = resp.json().get("data", {}).get("question")
            if data:
                return data
        except Exception as e:
            print(f"  attempt {i+1} failed: {e}")
            time.sleep(2)
    return None


def main():
    src = ROOT / f"{NUM}.sql"
    if not src.exists():
        print(f"{src} not found - has it already been moved/renamed?")
        return

    print("Fetching problem index to resolve slug...")
    resp = requests.get(PROBLEMS_LIST_URL, timeout=20)
    resp.raise_for_status()
    index = {
        str(item["stat"]["frontend_question_id"]): item["stat"]["question__title_slug"]
        for item in resp.json()["stat_status_pairs"]
    }
    slug = index.get(str(NUM))
    if not slug:
        print(f"Could not resolve slug for #{NUM} from the problems index.")
        return

    print(f"Resolved slug: {slug}. Fetching details (with retries)...")
    detail = fetch_with_retry(slug)
    if not detail:
        print("Still failed after retries. Try again later or check connectivity.")
        return

    title = detail["title"]
    difficulty = detail["difficulty"]
    folder = topic_folder(detail["topicTags"])
    new_name = f"{NUM}-{slugify(title)}.sql"
    dst_dir = ROOT / folder
    dst_dir.mkdir(parents=True, exist_ok=True)
    dst = dst_dir / new_name

    shutil.move(str(src), str(dst))
    print(f"Moved -> {folder}/{new_name}")

    readme_path = ROOT / "README.md"
    text = readme_path.read_text(encoding="utf-8")

    link = f"https://leetcode.com/problems/{slugify(title)}/"
    new_row = (
        f"| {NUM} | [{title}]({link}) | {difficulty} | {folder} | sql | "
        f"`{folder}/{new_name}` |"
    )

    pattern = re.compile(rf"^\| {NUM} \|.*\|$", re.MULTILINE)
    if pattern.search(text):
        text = pattern.sub(new_row, text)
        print("Patched existing README row.")
    else:
        text = text.rstrip() + "\n" + new_row + "\n"
        print("Appended new README row.")

    readme_path.write_text(text, encoding="utf-8")
    print("README.md updated.")
    print(f"\nDone: #{NUM} \"{title}\" [{difficulty}] -> {folder}/{new_name}")


if __name__ == "__main__":
    main()
