class Solution {
public:
    const int MOD = 1e9 + 7;
    int n, m, K;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int r, int c, int rem) {
        if (r == n-1 && c == m-1) {
            return ((rem + grid[r][c]) % K == 0);
        }

        int& ans = dp[r][c][rem];
        if (ans != -1) return ans;
        ans = 0;

        int newRem = (rem + grid[r][c]) % K;

        if (r + 1 < n)
            ans = (ans + solve(grid, r+1, c, newRem)) % MOD;
        if (c + 1 < m)
            ans = (ans + solve(grid, r, c+1, newRem)) % MOD;

        return ans;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        K = k;
        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return solve(grid, 0, 0, 0);
    }
};
