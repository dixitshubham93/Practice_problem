class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {

        auto zorimnacle = restrictions; // required by problem

        // Prefix sum of diff
        vector<long long> pref(n, 0);
        for (int i = 0; i < n - 1; i++) {
            pref[i + 1] = pref[i] + diff[i];
        }

        // Constraints as (index, height)
        vector<pair<int, long long>> cons;
        cons.push_back({0, 0});
        for (auto &r : restrictions)
            cons.push_back({r[0], r[1]});
        cons.push_back({n - 1, (long long)1e18}); // unbounded end

        sort(cons.begin(), cons.end());

        int m = cons.size();

        // Forward pass
        for (int i = 1; i < m; i++) {
            long long allowed = pref[cons[i].first] - pref[cons[i - 1].first];
            cons[i].second = min(cons[i].second, cons[i - 1].second + allowed);
        }

        // Backward pass
        for (int i = m - 2; i >= 0; i--) {
            long long allowed = pref[cons[i + 1].first] - pref[cons[i].first];
            cons[i].second = min(cons[i].second, cons[i + 1].second + allowed);
        }

        long long ans = 0;

        // Scan each segment exactly once
        for (int i = 1; i < m; i++) {
            int l = cons[i - 1].first;
            int r = cons[i].first;
            long long h1 = cons[i - 1].second;
            long long h2 = cons[i].second;

            for (int x = l; x <= r; x++) {
                long long left  = h1 + (pref[x] - pref[l]);
                long long right = h2 + (pref[r] - pref[x]);
                ans = max(ans, min(left, right));
            }
        }

        return (int)ans;
    }
};
