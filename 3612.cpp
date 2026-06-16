// You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.
// Build a new string result by processing s according to the following rules from left to right:
// If the letter is a lowercase English letter append it to result.
// A '*' removes the last character from result, if it exists.
// A '#' duplicates the current result and appends it to itself.
// A '%' reverses the current result.
// Return the final string result after processing all characters in s.

class Solution {
public:
    string processStr(string s) {
        string ans;
        for(char c:s){
            if(c=='*'){
                if(ans.size()>0){
                    ans.erase(ans.size()-1);
                }
            }
            else if(c=='#'){
                ans+=ans;
            }
            else if(c=='%'){
                reverse(ans.begin(),ans.end());
            }
            else{
                ans+=c;
            }
        }
        return ans;
    }
};
