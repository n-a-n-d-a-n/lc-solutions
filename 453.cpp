// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
// In one move, you can increment n - 1 elements of the array by 1.

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int moves=0;
        int min=nums[0];
        for(int i=0;i<n;i++){
            moves+=nums[i]-min;
        }
        return moves;
    }
};
