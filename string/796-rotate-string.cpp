// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.

class Solution {
public:
    bool rotateString(string s, string goal) {
        for(char c:s){
            if(s==goal){
                return true;
            }
            rotate(s.begin(),s.begin()+1,s.end());
        }
        return false;
    }
};
