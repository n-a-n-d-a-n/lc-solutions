// You are given an integer array nums and an integer digit.
// Return the total number of times digit appears in the decimal representation of all elements in nums.

class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int temp=nums[i];
            if(temp==0){
                if(digit==0){
                    count++;
                }
                continue;
            }
            while(temp>0){
                int rem=temp%10;
                temp/=10;
                if(rem==digit){
                    count++;
                }
            }
        }
        return count;
    }
};
