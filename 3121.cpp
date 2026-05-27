// You are given a string word.
// A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.
// Return the number of special letters in word.

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> size(26,0);
        for(char c:word){
            if(islower(c)){
                size[c-'a']|=1;
            }
            else{
                size[c-'A']|=2;
            }
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(size[i]==3){
                count++;
            }
        }
        return count;
    }
};
