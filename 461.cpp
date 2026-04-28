// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
// Given two integers x and y, return the Hamming distance between them.

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n=x^y;
        string binStr="";
        if(n==0){
            return 0;
        }
        while(n>0){
            int rem=n%2;
            if(rem==1){
                binStr+="1";
            }
            else{
                binStr+="0";
            }
            n=n/2;
        }
        int count=0;
        for(int i=0;i<binStr.length();i++){
            if(binStr[i]=='1'){
                count++;
            }
        }
        return count;
    }
};
