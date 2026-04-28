class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void DSU(int n) {
        parent.assign(n, 0);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
            return;
        if (size[rootx] >= size[rooty]) {
            parent[rooty] = rootx;
            size[rootx] += size[rooty];
        } else {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {-1, 1, 0, 0};
        vector<vector<int>> dirs = {{},     {0, 1}, {2, 3}, {0, 2},
                                    {1, 2}, {0, 3}, {1, 3}};

        DSU(m * n );

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int type = grid[i][j];
                for (int dir : dirs[type]) {
                    int newr = dr[dir] + i;
                    int newc = dc[dir] + j;
                    if (newr < 0 || newr >= n || newc < 0 || newc >= m)
                        continue;
                    int nextype = grid[newr][newc];
                    for (int nextdir : dirs[nextype]) {

                        if (dr[dir] == -dr[nextdir] &&
                            dc[dir] == -dc[nextdir]) {
                            Union(i * m + j, newr * m + newc);
                            break;
                        }
                    }
                }
            }
        }

        return find(0) == find(n * m - 1);
    }
};