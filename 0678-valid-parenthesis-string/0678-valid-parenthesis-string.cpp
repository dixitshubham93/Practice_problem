class Solution {
public:
    vector<vector<int>> dp;

    bool dfs(string &s, int count, int index, int n) {
        if (index == n) return count == 0;
        if (count < 0) return false;

        int offset = n;
        if (dp[index][count + offset] != INT_MIN)
            return dp[index][count + offset];

        bool res = false;
        if (s[index] == '(')
            res = dfs(s, count + 1, index + 1, n);
        else if (s[index] == ')')
            res = dfs(s, count - 1, index + 1, n);
        else 
            res = dfs(s, count + 1, index + 1, n) ||
                  dfs(s, count - 1, index + 1, n) ||
                  dfs(s, count, index + 1, n);

        return dp[index][count + offset] = res;
    }

    bool checkValidString(string s) {
        int n = s.size();
        dp.assign(n + 1, vector<int>(2 * n + 1, INT_MIN));
        return dfs(s, 0, 0, n);
    }
};
