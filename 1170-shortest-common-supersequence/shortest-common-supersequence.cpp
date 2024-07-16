class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        // Finding length of LCS(Tabulation)
        int m = text1.size(), n = text2.size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = m - 1 ; i >= 0 ; i--){
            for(int j = n - 1 ; j >= 0 ; j--){
                if(text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        // ------------------------------------------------------------ 
        // Printing supersequence(Variation of printing LCS)

        int i = 0, j = 0;
        string ans;
        while(i < m && j < n){
            if(text1[i] == text2[j]){
                ans.push_back(text1[i]);
                i++, j++;
            }
            else if(dp[i + 1][j] > dp[i][j + 1]){
                ans.push_back(text1[i]);
                i++;
            }
            else{
                ans.push_back(text2[j]);
                j++;
            }
        }
        while(j < n)
            ans.push_back(text2[j++]);
        while(i < m)
            ans.push_back(text1[i++]);
        return ans;
    }
};