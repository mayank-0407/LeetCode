class Solution {
public:
    int f(int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(n>=0 && m>=0 && grid[n][m]==1) return 0;
        if(n==0 && m==0) return 1;
        if(n<0 || m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int up=f(n-1,m,grid,dp);
        int down=f(n,m-1,grid,dp);
        return dp[n][m]=up+down;
    }
    // int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    //     int n=grid.size(),m=grid[0].size();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     int ans=f(n-1,m-1,grid,dp);
    //     return ans;
    // }
        int uniquePathsWithObstacles(vector<vector<int>>& G) {
        int n = (int)G.size();
        int m = (int)G[0].size();

        vector<vector<int>> dp(n + 4, vector<int> (m + 4, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 and j == 0  and !G[i][j]) {
                    dp[i][j] = 1;
                }
                else if (!G[i][j]) {
                    if (i) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    if (j) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};