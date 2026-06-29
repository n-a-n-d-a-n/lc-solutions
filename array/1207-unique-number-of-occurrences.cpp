// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> counts;
        for(int i=0;i<arr.size();i++){
            int count=1;
            for(;i+1<arr.size()&&arr[i]==arr[i+1];i++){
                count++;
            }
            counts.push_back(count);
        }
        sort(counts.begin(),counts.end());
        for(int i=0;i<counts.size()-1;i++){
            if(counts[i]==counts[i+1]){
                return false;
            }
        }
        return true;
    }
};
