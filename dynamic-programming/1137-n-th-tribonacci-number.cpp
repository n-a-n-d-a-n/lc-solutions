// Problem: 1137 - N-th Tribonacci Number
// Approach: Iterative rolling sum of last 3 terms, O(n) time O(1) space

class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1||n==2){
            return 1;
        }
        int a=0;
        int b=1;
        int c=1;
        for(int i=3;i<=n;i++){
            int ans=a+b+c;
            a=b;
            b=c;
            c=ans;
        }
        return c;
    }
};
