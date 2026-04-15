class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int size = grid.size();
        if (grid[0][0] != 0 || grid[size - 1][size - 1] != 0) {
            return -1;
        }
        if(size==1){return 1;}
        
        int dr[8] = {0, 0, 1, -1, 1, -1, -1, 1};
        int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        int level = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty()){
            int n = q.size();
            level++;
            while (n--) {
                auto [row, col] = q.front();
                q.pop();
                for (int i = 0; i < 8; i++) {
                    int newrow = row + dr[i];
                    int newcol = col + dc[i];
                    if (newrow < 0 || newrow >= size || newcol < 0 ||
                        newcol >= size) {
                        continue;
                    }
                    if (newrow == (size - 1) && newcol == (size - 1)) {
                        return level;
                    }
                    if (grid[newrow][newcol] == 0) {
                        grid[newrow][newcol] = 1;
                        q.push({newrow, newcol});
                    }
                }
            }
        }
        return -1;
    }
};