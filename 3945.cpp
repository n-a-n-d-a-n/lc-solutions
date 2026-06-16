// You are given an integer n.
// The score of n is defined as the sum of d * freq(d) over all distinct digits d, where freq(d) denotes the number of times the digit d appears in n.
// Return an integer denoting the score of n.

class Solution {
public:
    int digitFrequencyScore(int n) {
        int sum=0;
        int rem=0;
        while(n>0){
            rem=n%10;
            sum+=rem;
            n/=10;
        }
        return sum;
    }
};
