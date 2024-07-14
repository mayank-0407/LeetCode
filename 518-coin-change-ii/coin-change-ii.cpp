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
    int change(int amount, vector<int>& arr) {
        int n=arr.size();
        // vector<vector<int>> dp(n,vector<int>(target+1,-1)); // for memoize
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int t=0;t<=amount;t++)
            if(t%arr[0]==0) dp[0][t]=1;

        for(int idx=1;idx<n;idx++){
            for(int target=0;target<=amount;target++){
                int nottake=dp[idx-1][target];
                int take =0;
                if(target>=arr[idx])
                    take=dp[idx][target-arr[idx]];
                dp[idx][target]=take+nottake;
            }
        }

        return dp[n-1][amount];
    }
};