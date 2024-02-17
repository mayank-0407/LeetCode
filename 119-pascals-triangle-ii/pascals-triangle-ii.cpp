class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascalTraingle(rowIndex+1);
        for (int row=0; row<=rowIndex; row++)
        {
            pascalTraingle[row] = vector<int>(row+1);
            for (int col = 0; col<row+1; col++)
            {
                if (col == 0 || col == row)
                    pascalTraingle[row][col] = 1;
                else
                {
                    pascalTraingle[row][col] = pascalTraingle[row-1][col-1] + pascalTraingle[row-1][col];
                }
            }
        }
        return pascalTraingle[rowIndex];
    }
};