class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;

        // dist[i][j][t] = minimum cost to reach (i,j) using t teleports
        vector<vector<vector<int>>> dist(
            m, vector<vector<int>>(n, vector<int>(k+1, INF))
        );

        // All cells sorted by value
        vector<tuple<int,int,int>> cells;
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cells.push_back({grid[i][j], i, j});

        sort(cells.begin(), cells.end());

        // Pointer for teleport unlock per teleport count
        vector<int> ptr(k + 1, 0);

        // Min-heap: (cost, i, j, usedTeleports)
        priority_queue<
            tuple<int,int,int,int>,
            vector<tuple<int,int,int,int>>,
            greater<>
        > pq;

        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});

        while (!pq.empty()) {
            auto [cost, i, j, t] = pq.top();
            pq.pop();

            if (cost > dist[i][j][t]) continue;

            // Reached destination
            if (i == m-1 && j == n-1) return cost;

            // Normal move: down
            if (i + 1 < m) {
                int nc = cost + grid[i+1][j];
                if (nc < dist[i+1][j][t]) {
                    dist[i+1][j][t] = nc;
                    pq.push({nc, i+1, j, t});
                }
            }

            // Normal move: right
            if (j + 1 < n) {
                int nc = cost + grid[i][j+1];
                if (nc < dist[i][j+1][t]) {
                    dist[i][j+1][t] = nc;
                    pq.push({nc, i, j+1, t});
                }
            }

            // Teleport unlock
            if (t < k) {
                while (ptr[t] < (int)cells.size()) {
                    auto [val, x, y] = cells[ptr[t]];
                    if (val > grid[i][j]) break;

                    // Teleport cost = 0
                    if (cost < dist[x][y][t+1]) {
                        dist[x][y][t+1] = cost;
                        pq.push({cost, x, y, t+1});
                    }
                    ptr[t]++;
                }
            }
        }

        return -1; // guaranteed reachable per problem statement
    }
};