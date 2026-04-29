class Solution {
public:
   
    long long memo[105][105][2]; 
    long long pref[105][105];

    long long solve(int col, int prev_h, int dec, int n){

        if (col == n) return 0;
        if (memo[col][prev_h][dec] != -1) return memo[col][prev_h][dec];

        long long res = 0;

        for (int curr_h = 0; curr_h <= n; curr_h++) {
            long long current_gain = 0;

            if (curr_h > prev_h) {
               
                if (dec == 0){
                    if (col > 0) {
                        current_gain += pref[curr_h][col - 1] - pref[prev_h][col - 1];
                    }
                } else {
                    // If we were decreasing and now we increase, we can only 
                    // gain points from the "future" side, which is handled 
                    // in the next column's recursive step.
                    current_gain = 0;
                }
                res = max(res, current_gain + solve(col + 1, curr_h, 0, n));
            } 
            else if (curr_h < prev_h) {
                
                current_gain += pref[prev_h][col] - pref[curr_h][col];
                res = max(res, current_gain + solve(col + 1, curr_h, 1, n));
            } 
            else {
                
                res = max(res, solve(col + 1, curr_h, 0, n));
            }
        }
        return memo[col][prev_h][dec] = res;
    }

    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Correct Prefix Sums: pref[height][col]
        // pref[h][j] stores sum of first h elements in column j
        for (int j = 0; j < n; j++) {
            pref[0][j] = 0;
            for (int i = 0; i < n; i++) {
                pref[i + 1][j] = pref[i][j] + grid[i][j];
            }
        }

        memset(memo, -1, sizeof(memo));
        
        // Start at column 0, previous height 0, not decreasing.
        return solve(0, 0, 0, n);
    }
};