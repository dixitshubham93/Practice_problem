class Solution {
public:
    int dp[503][503];

    int Solve(vector<int>& prefix, int start, int end) {
        if (start == end) return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int ans = 0;

        for (int temp = start; temp < end; temp++) {
            int left = prefix[temp] - prefix[start - 1];
            int right = prefix[end] - prefix[temp];

            if (left == right) {
                ans = max(ans, left + Solve(prefix, start, temp));
                ans = max(ans, right + Solve(prefix, temp + 1, end));
            }
            else if (left < right) {
                ans = max(ans, left + Solve(prefix, start, temp));
            }
            else {
                ans = max(ans, right + Solve(prefix, temp + 1, end));
            }
        }

        return dp[start][end] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        memset(dp, -1, sizeof(dp));

        return Solve(prefix, 1, n);
    }
};