// Problem: 213 - House Robber II
// Approach: Circular array -> run House Robber I twice, excluding first house and excluding last house, take max

class Solution {
public:
    int chori(vector<int> &nums,int start,int end){
        int prev1=0;
        int prev2=0;
        for(int i=start;i<=end;i++){
            int c_max=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=c_max;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        return max(chori(nums,0,n-2),chori(nums,1,n-1));
    }
};
