// You are given an integer array nums.
// The alternating sum of nums is the value obtained by adding elements at even indices and subtracting elements at odd indices. That is, nums[0] - nums[1] + nums[2] - nums[3]...
// Return an integer denoting the alternating sum of nums.

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ans+=nums[i];
            }
            if(i%2!=0){
                ans-=nums[i];
            }
        }
        return ans;
    }
};
