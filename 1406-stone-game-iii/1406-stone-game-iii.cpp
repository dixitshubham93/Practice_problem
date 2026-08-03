typedef long long ll;

class Solution {
public:
    vector<vector<ll>> dp;

    ll solve(vector<int>& st, int pos, int turn) {
        if (pos >= st.size()) return 0;

        if (dp[pos][turn] != LLONG_MIN)
            return dp[pos][turn];

        ll ans;

        if (turn == 0) {
            ans = st[pos] + solve(st, pos + 1, 1);

            if (pos + 1 < st.size())
                ans = max(ans,
                          (ll)st[pos] + st[pos + 1] +
                          solve(st, pos + 2, 1));

            if (pos + 2 < st.size())
                ans = max(ans,
                          (ll)st[pos] + st[pos + 1] + st[pos + 2] +
                          solve(st, pos + 3, 1));
        } else {
            ans = -st[pos] + solve(st, pos + 1, 0);

            if (pos + 1 < st.size())
                ans = min(ans,
                          -(ll)st[pos] - st[pos + 1] +
                          solve(st, pos + 2, 0));

            if (pos + 2 < st.size())
                ans = min(ans,
                          -(ll)st[pos] - st[pos + 1] - st[pos + 2] +
                          solve(st, pos + 3, 0));
        }

        return dp[pos][turn] = ans;
    }

    string stoneGameIII(vector<int>& st) {
        int n = st.size();
        dp.assign(n, vector<ll>(2, LLONG_MIN));

        ll diff = solve(st, 0, 0);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};