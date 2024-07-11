class Solution {
public:
    int f(vector<vector<int>>& grid,int n,int m,vector<vector<int>>& dp){
        if(n==0 && m==0) return grid[n][m];
        if(n<0 || m<0) return 1e9;
        if(dp[n][m]!=-1) return dp[n][m];
        int up=grid[n][m]+f(grid,n-1,m,dp);
        int down=grid[n][m]+f(grid,n,m-1,dp);
        return dp[n][m]=min(up,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=f(grid,n-1,m-1,dp);
        return ans;
    }
};