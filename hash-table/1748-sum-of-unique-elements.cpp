class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int> count;
        for(int num:nums){
            count[num]++;
            if(count[num]==1){
                sum+=num;
            }
            if(count[num]==2){
                sum-=num;
            }
        }
        return sum;
    }
};
