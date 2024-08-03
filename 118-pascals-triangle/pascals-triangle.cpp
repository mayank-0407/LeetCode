class Solution {
public:
    vector<int> generateRow(int row){
        vector<int> newRow;
        newRow.push_back(1);
        long long ans = 1;
        for(int col = 1;col < row; col++){
            ans *= (row-col);
            ans /= col;
            newRow.push_back(ans);
        }
        return newRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row = 1; row <= numRows; row++){
            vector<int> nextRow = generateRow(row);
            ans.push_back(nextRow);
        }
        return ans;
    }
};