class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        if (grid[0][0] == 1)return -1;
        if(n==1&&grid[0][0]==0)return 1;
        q.push({0, 0});
        int count = 0;

        visited[0][0] = 1;
        while (!q.empty()) {

            int size = q.size();
            count++;
            for (int l = 0; l < size; l++) {
                auto it = q.front();
                int raw = it.first;
                int col = it.second;
                q.pop();
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        int ri = i + raw;
                        int ci = j + col;
                        if (ri >= 0 && ri < n && ci >= 0 && ci < n &&
                            !visited[ri][ci] && grid[ri][ci] == 0) {
                            q.push({ri, ci});
                            visited[ri][ci] = 1;
                            if(ri==n-1&&ci==n-1)return count+1;
                        }
                    }
                }
            }
        }
       return -1;
    }
};