class Solution {
public:
    int dp[13][10001];

    int solve(vector<int>& coin, int idx, int amount) {
        if (amount == 0) return 0;
        if (idx < 0) return 1e9;

        if (dp[idx][amount] != -1) return dp[idx][amount];

        int notTake = solve(coin, idx - 1, amount);

        int take = 1e9;
        if (coin[idx] <= amount) {
            take = 1 + solve(coin, idx, amount - coin[idx]);
        }

        return dp[idx][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int res = solve(coins, coins.size() - 1, amount);
        return res >= 1e9 ? -1 : res;
    }
};