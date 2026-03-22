class Solution {
public:
    int dp[1001][1001];

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, 0, sizeof(dp));
        int n = text1.size();
        int m = text2.size();
        
        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= m; i2++) {

            if (text1[i1 - 1] == text2[i2 - 1]) {
                    dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
                 
                }else{
                 dp[i1][i2] = max( dp[i1][i2 - 1], dp[i1 - 1][i2]); 
                }              
            }
        }
        return dp[n][m];
    }
};