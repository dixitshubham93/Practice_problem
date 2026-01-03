class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long dp[5001][2];

    long long solve(int row, int total, int type) {
        if (row == total) return 1;

        if (dp[row][type] != -1) return dp[row][type];

        if (type == 0) {
            return dp[row][type] =
                (2LL * solve(row + 1, total, 0) +
                 2LL * solve(row + 1, total, 1)) % MOD;
        } else {
            return dp[row][type] =
                (2LL * solve(row + 1, total, 0) +
                 3LL * solve(row + 1, total, 1)) % MOD;
        }
    }

    int numOfWays(int n) {
        if (n == 1) return 12;

        memset(dp, -1, sizeof(dp));

        long long aba = (6LL * solve(1, n, 0)) % MOD;
        long long abc = (6LL * solve(1, n, 1)) % MOD;

        return (aba + abc) % MOD;
    }
};
