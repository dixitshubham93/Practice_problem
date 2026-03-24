class Solution {
public:
    int MOD = 12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int total = n * m;

        vector<int> prefix(total, 1), suffix(total, 1);

        
        for (int i = 1; i < total; i++) {
            int prev_i = (i - 1) / m;
            int prev_j = (i - 1) % m;

            prefix[i] = ((prefix[i - 1] % MOD)*(grid[prev_i][prev_j]% MOD))% MOD;
        }

        
        for (int i = total - 2; i >= 0; i--) {
            int next_i = (i + 1) / m;
            int next_j = (i + 1) % m;

            suffix[i] = ((suffix[i + 1] % MOD)*( grid[next_i][next_j]% MOD)) % MOD;
        }

        
        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < total; i++) {
            int r = i / m;
            int c = i % m;

            ans[r][c] = ((prefix[i] % MOD)*(suffix[i]% MOD)) % MOD;
        }

        return ans;
    }
};