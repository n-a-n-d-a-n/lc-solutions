// You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.
// Return the minimum number of steps to make t an anagram of s.
// An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count(26,0);
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        int steps=0;
        for(int i=0;i<26;i++){
            if(count[i]>0){
                steps+=count[i];
            }
        }
        return steps;
    }
};
