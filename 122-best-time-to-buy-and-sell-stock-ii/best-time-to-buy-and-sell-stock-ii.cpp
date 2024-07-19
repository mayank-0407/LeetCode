class Solution {
public:
    int f(int idx, int canbuy,vector<int> &prices, vector<vector<int>> &dp){
        if(idx == prices.size()) return 0;
        if(dp[idx][canbuy] != -1) return dp[idx][canbuy];

        int profit=0;
        if(canbuy){
            profit = max(-prices[idx] + f(idx+1, 0, prices, dp),0 + f(idx+1,1,prices, dp));
        }else{
            profit = max(prices[idx] + f(idx+1, 1, prices, dp),0 + f(idx+1, 0, prices, dp));
        }
        return dp[idx][canbuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};