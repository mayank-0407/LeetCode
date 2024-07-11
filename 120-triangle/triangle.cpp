class Solution {
public:
    int f(vector<vector<int>>& triangle,int n,int m,vector<vector<int>>& dp){
        if(n==triangle.size()-1) return triangle[n][m];
        if(dp[n][m]!=-1) return dp[n][m];
        int down=triangle[n][m]+f(triangle,n+1,m,dp);
        int diag=triangle[n][m]+f(triangle,n+1,m+1,dp);

        return dp[n][m]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=f(triangle,0,0,dp);
        return ans;
    }
};