// You are given a positive integer n.
// Let digitSum be the sum of the digits of n, and let squareSum be the sum of the squares of the digits of n.
// An integer is called good if squareSum - digitSum >= 50.
// Return true if n is good. Otherwise, return false.

class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum=0;
        int squareSum=0;
        int temp=n;
        while(temp>0){
            int rem=temp%10;
            digitSum+=rem;
            squareSum+=rem*rem;
            temp/=10;
        }
        if(squareSum-digitSum>=50){
            return true;
        }
        return false;
    }
};
