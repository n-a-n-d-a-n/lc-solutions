class Solution {
public:
    vector<int> rows(int row){
        long long ans=1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col=1;col<row;col++){
            ans*=(row-col);
            ans/=col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pT;
        for(int i=1;i<=numRows;i++){
            pT.push_back(rows(i));
        }
        return pT;
    }
};
