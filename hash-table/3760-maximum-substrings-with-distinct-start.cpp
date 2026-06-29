// You are given a string s consisting of lowercase English letters.
// Return an integer denoting the maximum number of substrings you can split s into such that each substring starts with a distinct character (i.e., no two substrings start with the same character).

class Solution {
public:
    int maxDistinct(string s) {
        vector<int> ascii_arr;
        int count=0;
        for(char c:s){
            int ascii=static_cast<int>(c);
            bool nonUniq=false;
            for(int already:ascii_arr){
                if(ascii==already){
                    nonUniq=true;
                    break;
                }
            }
            if(!nonUniq){
                ascii_arr.push_back(ascii);
                count++;
            }
        }
        return count;
    }
};
