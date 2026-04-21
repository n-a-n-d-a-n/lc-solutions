// There are n houses evenly lined up on the street, and each house is beautifully painted.
// You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.
// Return the maximum distance between two houses with different colors.
// The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(colors[i]!=colors[j]){
                    k=max(k,j-i);
                }
            }
        }
        return abs(k);
    }
};
