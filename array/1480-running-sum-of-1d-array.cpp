// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
// Return the running sum of nums.

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> sum(n);
        int tSum=0;
        sum[0]=nums[0];
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+nums[i];
        }
        return sum;
    }
};
