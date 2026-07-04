class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        while(n>1){
            n=nums.size();
            vector<int> triA;
            for(int i=0;i<n-1;i++){
                int arrS=(nums[i]+nums[i+1])%10;
                triA.push_back(arrS);
            }
            nums=triA;
        }
        return nums[0];
    }
};
