// You are given an integer array nums of length n.
// A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty subarrays such that:
// Left subarray contains indices [0, i].
// Right subarray contains indices [i + 1, n - 1].
// Return the number of partitions where the difference between the sum of the left and right subarrays is even.

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n-1;i++){
            sum1+=nums[i];
            sum2=sum-sum1;
            if((sum1-sum2)%2==0){
                count++;
            }
        }
        return count;
    }
};
