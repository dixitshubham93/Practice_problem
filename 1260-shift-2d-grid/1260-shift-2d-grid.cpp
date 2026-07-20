class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        queue<int>q;
        int n = grid.size();
        int m = grid[0].size();
        k = k%(n*m);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                q.push(grid[i][j]);
                if(q.size()>k){
                    grid[i][j] = q.front();
                    q.pop();
                }
            }
        }
        for(int i = 0;i<n;i++){
             if(q.empty()){break;}
            for(int j = 0;j<m;j++){
                if(q.empty()){break;}
                    grid[i][j] = q.front();
                    q.pop();
            }
        }
        return grid;
    }
};