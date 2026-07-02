class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<pair<int, pair<int, int>>> q;
        int n = grid.size() - 1;
        int m = grid[0].size() - 1;
        if (n == 0 && m == 0)
            return true;
        if (grid[0][0] == 1) {
            q.push({health - 1, {0, 0}});
        } else {
            q.push({health, {0, 0}});
        }
        grid[0][0] = 2;
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            int health = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
             if (x == n && y == m && health >= 1) {
                        return true;
                }
            for (int i = 0; i < 4; i++) {
                int newr = x + dr[i];
                int newc = y + dc[i];
                if (newr >= 0 && newr <= n && newc >= 0 && newc <= m &&
                    grid[newr][newc] != 2) {
                    int newHealth = health;
                    if (grid[newr][newc] == 1) {
                        newHealth--;
                    }
                    if (newr == n && newc == m && newHealth >= 1) {
                        return true;
                    }
                    q.push({newHealth, {newr, newc}});
                    grid[newr][newc] = 2;
                }
            }
        }
        return false;
        }
    };