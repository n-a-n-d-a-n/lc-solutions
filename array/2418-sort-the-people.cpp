// You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
// For each index i, names[i] and heights[i] denote the name and height of the ith person.
// Return names sorted in descending order by the people's heights.

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<pair<int,string>> p(n);
        for(int i=0;i<n;i++){
            p[i]={heights[i],names[i]};
        }
        sort(p.begin(),p.end());
        reverse(p.begin(),p.end());
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=p[i].second;
        }
        return ans;
    }
};
