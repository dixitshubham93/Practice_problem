class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int timer = -1;
        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            int size = q.size();
            timer++;
            for (int i = 0; i < size; i++) {
                auto it = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int row = it.first + dr[j];
                    int col = it.second + dc[j];
                    if (row < 0 || row >= n || col < 0 || col >= m) {
                        continue;
                    }
                    if (grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.push({row, col});
                    }
                }
            }        
           
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return timer==-1?0:timer;
    }
};