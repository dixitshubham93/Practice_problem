class Solution {
public:
   int dp[502][502][3];

int maximumAmount(vector<vector<int>>& coins) {
    int n = coins.size(), m = coins[0].size();

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            for(int k = 0; k <= 2; k++){

                if(i == n-1 && j == m-1){
                    if(coins[i][j] < 0 && k > 0)
                        dp[i][j][k] = max(0, coins[i][j]);
                    else
                        dp[i][j][k] = coins[i][j];
                    continue;
                }

                int ans = INT_MIN;

                if(j+1 < m){
                    ans = max(ans, coins[i][j] + dp[i][j+1][k]);
                }

                if(i+1 < n){
                    ans = max(ans, coins[i][j] + dp[i+1][j][k]);
                }

                if(coins[i][j] < 0 && k > 0){
                    if(j+1 < m)
                        ans = max(ans, dp[i][j+1][k-1]);
                    if(i+1 < n)
                        ans = max(ans, dp[i+1][j][k-1]);
                }

                dp[i][j][k] = ans;
            }
        }
    }

    return dp[0][0][2];
}
};