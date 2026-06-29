// LeetCode 1967 - Number of Strings That Are Substrings of a Given String
// https://leetcode.com/problems/number-of-strings-that-are-substrings-in-word/
// Description: Given an array of strings `patterns` and a string `word`,
// return the number of strings in patterns that exist as a substring in word.
// Approach: brute force - check each pattern with string::find
// Time: O(n*m) | Space: O(1)

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(string pat:patterns){
            if(word.find(pat)!=string::npos){
                count++;
            }
        }
        return count;
    }
};
