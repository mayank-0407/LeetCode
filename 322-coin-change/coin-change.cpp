class Solution {
public:
    int f(int idx,int target,vector<int> &coins,vector<vector<int>> &dp){
        if(idx==0){
            if(target%coins[idx]==0) return target/coins[idx];
            else
                return 1e9;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int nottake=f(idx-1,target,coins,dp);
        int take=1e9;
        if(target>=coins[idx]) take=1+f(idx,target-coins[idx],coins,dp);
        return  dp[idx][target]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int target) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int ans=f(n-1,target,coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};