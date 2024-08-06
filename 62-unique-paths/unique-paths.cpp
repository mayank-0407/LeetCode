class Solution {
public:
    int getPaths(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        ans += getPaths(m, n, i - 1, j, dp); // Go up
        ans += getPaths(m, n, i, j - 1, dp); // Go left
        return dp[i][j] = ans;
    }
    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1) return 1;
        vector<vector<int>> dp(m , vector<int>(n, -1));
        getPaths(m, n, m - 1, n - 1, dp); 
        return dp[m-1][n-1];
    }
};