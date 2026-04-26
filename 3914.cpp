// You are given an integer array nums of length n.
// In one operation, you may choose any subarray nums[l..r] and increase each element in that subarray by x, where x is any positive integer.
// Return the minimum possible sum of the values of x across all operations required to make the array non-decreasing.
// An array is non-decreasing if nums[i] <= nums[i + 1] for all 0 <= i < n - 1.

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                ans+=nums[i]-nums[i+1];
            }
        }
        return ans;
    }
};
