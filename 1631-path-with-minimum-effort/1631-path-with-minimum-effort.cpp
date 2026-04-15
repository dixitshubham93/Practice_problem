class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        pq.push({0, {0, 0}});

        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
        efforts[0][0] = 0;

        int rv[4] = {-1, 0, 1, 0};
        int cv[4] = {0, -1, 0, 1};

        while (!pq.empty()) {
            auto [eff, pos] = pq.top();
            auto [r, c] = pos;
            pq.pop();

            
            if (eff > efforts[r][c]) continue;

            if (r == n-1 && c == m-1) return eff;

            for (int i = 0; i < 4; i++) {
                int nr = r + rv[i];
                int nc = c + cv[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newEff = max(eff, abs(heights[r][c] - heights[nr][nc]));

                    if (newEff < efforts[nr][nc]) {
                        efforts[nr][nc] = newEff;
                        pq.push({newEff, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};