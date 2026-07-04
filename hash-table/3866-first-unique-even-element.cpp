class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> uniQ;
        for(int num:nums){
            uniQ[num]++;
        }
        for(int num:nums){
            if(num%2==0&&uniQ[num]==1){
                return num;
            }
        }
        return -1;
    }
};
