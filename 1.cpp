// Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>store;
        for(int i=0;i<nums.size();i++){
            store.push_back({nums[i],i});
        }
        sort(store.begin(),store.end());
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            int sum=store[left].first+store[right].first;
            if(sum==target){
                return{store[left].second,store[right].second};
            }
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        return {};
    }
};
