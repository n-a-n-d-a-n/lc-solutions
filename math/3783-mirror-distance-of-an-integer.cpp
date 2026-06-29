// You are given an integer n.
// Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n.
// Return an integer denoting the mirror distance of n​​​​​​​.
// abs(x) denotes the absolute value of x.

class Solution {
public:
    int mirrorDistance(int n) {
        int rev=0;
        int temp=n;
        while(temp>0){
            int rem=temp%10;
            rev=rev*10+rem;
            temp/=10;
        }
        return abs(n-rev);
    }
};
