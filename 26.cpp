// Given an integer array nums sorted in non-decreasing order,
// remove the duplicates in-place such that each unique element appears only once.
// The relative order of the elements should be kept the same.
// Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​.
// After removing duplicates, return the number of unique elements k.
// The first k elements of nums should contain the unique numbers in sorted order.
// The remaining elements beyond index k - 1 can be ignored.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int n=nums.size();
        int count=0;
        for(int j=1;j<n;j++){
            if(nums[j]!=nums[count]){
                count++;
                nums[count]=nums[j];
            }
        }
        return count+1;
    }
};
