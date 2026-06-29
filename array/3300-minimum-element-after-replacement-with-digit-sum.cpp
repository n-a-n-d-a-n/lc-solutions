// You are given an integer array nums.
// You replace each element in nums with the sum of its digits.
// Return the minimum element in nums after all replacements.

class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            int temp=nums[i];
            while(temp>0){
                sum+=temp%10;
                temp/=10;
            }
            nums[i]=sum;
        }
        sort(nums.begin(),nums.end());
        return nums[0];
    }
};
