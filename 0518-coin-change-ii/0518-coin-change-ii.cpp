class Solution {
public:
    int dp[301][5001];

    int solve(vector<int>& coin, int idx, int amount) {
        if (amount == 0) return 1;
        if (idx < 0||amount<0) return 0;

        if (dp[idx][amount] != -1) return dp[idx][amount];

        int notTake = solve(coin, idx - 1, amount);

        int take = 0;
        if (coin[idx] <= amount) {
            take += solve(coin, idx, amount - coin[idx]);
        }

        return dp[idx][amount] = (take + notTake);
    }

    int change(int amount,vector<int>& coins){
        memset(dp, -1, sizeof(dp));
        int res = solve(coins, coins.size() - 1, amount);
        return res;
    }
};