# Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
# Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.
# In the American keyboard:
# the first row consists of the characters "qwertyuiop",
# the second row consists of the characters "asdfghjkl", and
# the third row consists of the characters "zxcvbnm".

class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        row1=set("qwertyuiop")
        row2=set("asdfghjkl")
        row3=set("zxcvbnm")
        result=[]
        for word in words:
            w_set=set(word.lower())
            if w_set.issubset(row1)|w_set.issubset(row2)|w_set.issubset(row3):
                result.append(word)
        return result
