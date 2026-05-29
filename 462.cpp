// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
// In one move, you can increment or decrement an element of the array by 1.
// Test cases are designed so that the answer will fit in a 32-bit integer.

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int moves=0;
        int n=nums.size();
        int min=0;
        int max=n-1;
        while(min<max){
            moves+=nums[max]-nums[min];
            min++;
            max--;
        }
        return moves;
    }
};
