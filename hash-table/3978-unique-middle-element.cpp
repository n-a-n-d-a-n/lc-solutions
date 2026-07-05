class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return false;
        }
        unordered_map<int,int> uniQ;
        for(int num:nums){
            uniQ[num]++;
        }
        int midV=nums[n/2];
        if(uniQ[midV]==1){
            return true;
        }
        return false;
    }
};
