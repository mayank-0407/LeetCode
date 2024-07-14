class Solution {
public:
    int f(int idx,int target,vector<int>& arr,vector<vector<int>> &dp){
        if(idx==0){
            if(target%arr[0]==0) return 1;
            return 0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int nottake=f(idx-1,target,arr,dp);
        int take =0;
        if(target>=arr[idx])
            take=f(idx,target-arr[idx],arr,dp);
        return dp[idx][target]=take+nottake;
    }
    int change(int target, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,coins,dp);
    }
};