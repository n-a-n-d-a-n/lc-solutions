// You are given a string s and an integer k.
// Reverse the first k characters of s and return the resulting string.

class Solution {
public:
    string reversePrefix(string s, int k) {
        reverse(s.begin(),s.begin()+k);
        return s;
    }
};
