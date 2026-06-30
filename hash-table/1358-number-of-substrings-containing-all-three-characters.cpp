class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int count=0;
        int a=-1;
        int b=-1;
        int c=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a=i;
            }
            else if(s[i]=='b'){
                b=i;
            }
            else if(s[i]=='c'){
                c=i;
            }
            if(a!=-1&&b!=-1&&c!=-1){
                int minI=min({a,b,c});
                count+=(minI+1);
            }
        }
        return count;
    }
};
