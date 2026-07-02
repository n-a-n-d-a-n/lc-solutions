// Problem: 198 - House Robber
// Approach: DP with two rolling variables (prev1 = best including/up to i, prev2 = best excluding i)

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int prev1=0;
        int prev2=0;
        for(int num:nums){
            int c_max=max(prev1,prev2+num);
            prev2=prev1;
            prev1=c_max;
        }
        return prev1;
    }
};
