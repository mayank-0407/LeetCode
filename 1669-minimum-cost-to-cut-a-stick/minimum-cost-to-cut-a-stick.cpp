class Solution {
public:
    int f(int i, int j, vector<int>& arr, vector<vector<int>> &dp){
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for (int k = i; k <= j; k++) {
            int steps = arr[j + 1] - arr[i - 1] + f(i, k - 1, arr, dp) + f(k + 1, j, arr, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }
    
    int minCost(int n, vector<int>& arr) {
        arr.push_back(n);
        arr.insert(arr.begin(), 0);
        sort(arr.begin(), arr.end());

        int c = arr.size();
        vector<vector<int>> dp(c, vector<int>(c, -1));
        return f(1, c - 2, arr, dp);
    }
};
