// You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.
// Return the minimum number of operations to make all elements of nums divisible by 3.

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%3==0){
                continue;
            }
            else if(nums[i]%3!=0){
                if((nums[i]-1)%3==0){
                    count++;
                }
                if((nums[i]+1)%3==0){
                    count++;
                }
            }
            else{
                return 0;
            }
        }
        return count;
    }
};
