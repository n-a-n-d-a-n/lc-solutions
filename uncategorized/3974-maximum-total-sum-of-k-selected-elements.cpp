// You are given an integer array nums and two integers k and mul.
// Select exactly k elements from nums. Process these elements one by one in any order you choose.
// For each selected element, independently choose one of the following:
// Add the element's value to the total sum, or
// Multiply the element by the current value of mul and add the result to the total sum.
// After processing each selected element, mul decreases by 1, regardless of which option was chosen. The current value of mul may become 0 or negative.
// Return an integer denoting the maximum possible total sum.

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long sum=0;
        for(int i=n-1;i>=n-k;i--){
            long long num=nums[i];
            long long prod=num*mul;
            sum+=max(num,prod);
            mul--;
        }
        return sum;
    }
};
