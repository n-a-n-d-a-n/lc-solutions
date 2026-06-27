// You are given two integers n and k.
// A positive integer x is called compatible if it satisfies both of the following conditions:
// abs(n - x) <= k
// (n & x) == 0
// Return the sum of all compatible integers x.
// Note:
// Here, & denotes the bitwise AND operator.
// The absolute difference between integers i and j is defined as abs(i - j).

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum=0;
        for(int x=1;x<=201;x++){
            if((abs(n-x)<=k)&&((n&x)==0)){
                sum+=x;
            }
        }
        return sum;
    }
};
