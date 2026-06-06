// You are given a 0-indexed integer array nums of size n.
// Define two arrays leftSum and rightSum where:
// leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
// rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
// Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer(n);
        int sum=0;
        int lSum=0;
        int rSum=0;
        sum=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<n;i++){
            rSum=sum-nums[i]-lSum;
            answer[i]=abs(rSum-lSum);
            lSum+=nums[i];
        }
        return answer;
    }
};
