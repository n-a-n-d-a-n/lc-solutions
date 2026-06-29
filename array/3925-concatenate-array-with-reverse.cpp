// You are given an integer array nums of length n.
// Construct a new array ans of length 2 * n such that the first n elements are the same as nums, and the next n elements are the elements of nums in reverse order.
// Formally, for 0 <= i <= n - 1:
// ans[i] = nums[i]
// ans[i + n] = nums[n - i - 1]
// Return an integer array ans.

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
