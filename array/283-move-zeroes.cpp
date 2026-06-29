// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[left],nums[i]);
                left++;
            }
        }
    }
};
