// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
// You can use each character in text at most once. Return the maximum number of instances that can be formed.

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0;
        int a=0;
        int l=0;
        int o=0;
        int n=0;
        vector<int> ans;
        for(char t:text){
            if(t=='b'){
                b++;
                ans.push_back(b);
            }
            else if(t=='a'){
                a++;
                ans.push_back(a);
            }
            else if(t=='l'){
                l++;
                ans.push_back(l);
            }
            else if(t=='o'){
                o++;
                ans.push_back(o);
            }
            else if(t=='n'){
                n++;
                ans.push_back(n);
            }
        }
        l/=2;
        o/=2;
        return min({b,a,l,o,n});
    }
};
