class Solution {
public:
    int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i==0 || j==0) return 0; // if index goes -ve we have 0 string as string length is over. here we are shifting indexes by 1 place.

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1]) return dp[i][j] = 1+f(i-1,j-1,s1,s2,dp); //match condition just add 1 and dec indexes
        else return dp[i][j]=0+max(f(i-1, j, s1, s2,dp),f(i, j-1, s1, s2,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1)); // recursion
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};