// You are given an integer array nums. Transform nums by performing the following operations in the exact order specified:
// Replace each even number with 0.
// Replace each odd numbers with 1.
// Sort the modified array in non-decreasing order.
// Return the resulting array after performing these operations.

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                ans[i]=0;
            }
            if(nums[i]%2!=0){
                ans[i]=1;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
