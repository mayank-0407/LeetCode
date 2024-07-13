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
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int T=0;T<=amount;T++){
            if(T%coins[0]==0) dp[0][T]=T/coins[0];
            else
                dp[0][T]=1e9;
        }

        for(int idx=1;idx<n;idx++){
            for(int target=0;target<=amount;target++){
                int nottake=dp[idx-1][target];
                int take=1e9;
                if(target>=coins[idx]) take=1+dp[idx][target-coins[idx]];
                dp[idx][target]=min(take,nottake);
            }
        }

        int ans=dp[n-1][amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};