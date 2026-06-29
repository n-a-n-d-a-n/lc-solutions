// Given an array of positive integers nums, return an array answer that consists of the digits of each integer in nums after separating them in the same order they appear in nums.
// To separate the digits of an integer is to get all the digits it has in the same order.
// For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        int n=nums.size();
        for(int n:nums){
            vector<int> keep;
            while(n>0){
                keep.push_back(n%10);
                n/=10;
            }
            for(int i=keep.size()-1;i>=0;i--){
                answer.push_back(keep[i]);
            }
        }
        return answer;
    }
};
