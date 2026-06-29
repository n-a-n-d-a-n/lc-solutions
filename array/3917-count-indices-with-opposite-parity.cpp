// LeetCode 3917 - Find Indices With Index Value Difference (Opposite Parity Score)
// https://leetcode.com/problems/count-of-substrings-with-opposite-parity/
// Description: For each index i, count indices j > i such that nums[i] and
// nums[j] have different parity (one even, one odd). Return array of scores.
// Approach: brute force - for each i, scan all j > i and compare parity
// Time: O(n^2) | Space: O(n)

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i+1;j<n;j++){
                if(nums[i]%2!=0&&nums[j]%2==0){
                    count++;
                }
                if(nums[i]%2==0&&nums[j]%2!=0){
                    count++;
                }
            }
            answer.push_back(count);
        }
        return answer;
    }
};
