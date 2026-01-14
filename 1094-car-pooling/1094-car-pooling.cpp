class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int mn = INT_MAX;
        int mx = INT_MIN;

        for (auto& it : trips) {
            mn = min(mn, it[1]);
            mx = max(mx, it[2]);
        }

        vector<int> path(mx - mn + 2, 0);

        for (auto& it : trips) {
            path[it[1] - mn] += it[0];
            path[it[2] - mn] -= it[0];   
        }

        int curr = 0;
        for (int i = 0; i <= mx - mn; i++) {
            curr += path[i];
            if (curr > capacity) return false;
        }

        return true;
    }
};
