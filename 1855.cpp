// You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.
// A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.
// Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.
// An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int o=nums2.size();
        int mDis=0;
        int j=0;
        for(int i=0;i<n;i++){
            if((o-1)-i<=mDis){
                break;
            }
            for(;j<o;j++){
                if(nums1[i]<=nums2[j]){
                    mDis=max(mDis,j-i);
                }
                else{
                    break;
                }
            }
        }
        return mDis;
    }
};
