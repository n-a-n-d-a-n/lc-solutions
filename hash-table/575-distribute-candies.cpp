class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        int limit=n/2;
        unordered_set<int> uniqueType(candyType.begin(),candyType.end());
        int size=uniqueType.size();
        return min(limit,size);
    }
};
