class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<bool>> visited1(n, vector<bool>(m, false));
    vector<vector<bool>> visited2(n, vector<bool>(m, false));

    queue<pair<int, int>> q;
    int dir[4] = {-1, 1, 0, 0};
    int dic[4] = {0, 0, -1, 1};

    
    for (int j = 0; j < m; j++) {
        visited1[0][j] = true;
        q.push({0, j});
    }
    for (int i = 0; i < n; i++) {
        visited1[i][0] = true;
        q.push({i, 0});
    }

    
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        int high = heights[row][col];
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = row + dir[k];
            int nc = col + dic[k];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && 
                heights[nr][nc] >= high && !visited1[nr][nc]) {
                visited1[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

 
    for (int j = 0; j < m; j++) {
        visited2[n-1][j] = true;
        q.push({n-1, j});
    }
    for (int i = 0; i < n; i++) {
        visited2[i][m-1] = true;
        q.push({i, m-1});
    }

   
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        int high = heights[row][col];
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = row + dir[k];
            int nc = col + dic[k];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && 
                heights[nr][nc] >= high && !visited2[nr][nc]) {
                visited2[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited1[i][j] && visited2[i][j]) {
                ans.push_back({i, j});
            }
        }
    }
    return ans;
}
};
