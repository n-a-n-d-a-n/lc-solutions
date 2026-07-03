class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans=1;
        vector<int> pT;
        pT.push_back(ans);
        for(int col=1;col<=rowIndex;col++){
            ans*=rowIndex-col+1;
            ans/=col;
            pT.push_back(ans);
        }
        return pT;
    }
};
