// You are given an integer array nums.
// In one move, you may increase the value of any single element nums[i] by 1.
// Return the minimum total number of moves required so that all elements in nums become equal.

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int max=nums[n-1];
        int moves=0;
        for(int i=0;i<n;i++){
            moves+=max-nums[i];
        }
        return moves;
    }
};
