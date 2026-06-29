// You are given two integers num1 and num2 representing an inclusive range [num1, num2].
// The waviness of a number is defined as the total count of its peaks and valleys:
// A digit is a peak if it is strictly greater than both of its immediate neighbors.
// A digit is a valley if it is strictly less than both of its immediate neighbors.
// The first and last digits of a number cannot be peaks or valleys.
// Any number with fewer than 3 digits has a waviness of 0.
// Return the total sum of waviness for all numbers in the range [num1, num2].

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count=0;
        for(int i=num1;i<=num2;i++){
            string s=to_string(i);
            int len=s.length();
            if(len<3){
                continue;
            }
            for(int j=1;j<len-1;j++){
                bool isPeak=(s[j]>s[j-1])&&(s[j]>s[j+1]);
                bool isValley=(s[j]<s[j-1]&&s[j]<s[j+1]);
                if(isPeak||isValley){
                    count++;
                }
            }
        }
        return count;
    }
};
