class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        if(grid[0][0]==1)return -1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int , int>>q;
        q.push({0 , 0});
        int dr[8] = {-1 , -1 , -1 , 1 , 1 , 1 ,0 , 0};
        int dc[8] = { 1, 0 , -1 , 1 , 0 , -1 , -1 , 1};
        int level = 1;
        if(0==(n-1)&&0==(m-1)){return level;}
        while(!q.empty()){
            int sz = q.size();
            if(sz>0){
            level++;
            }
            for(int j = 0;j<sz;j++){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0;i<8;i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if(nrow<0||nrow>=n||ncol<0||ncol>=m||grid[nrow][ncol]==1){
                 continue;
                }
                grid[nrow][ncol] = 1;
                if(nrow==(n-1)&&ncol==(m-1)){return level;}
                q.push({nrow , ncol});
            }
        }
      
      }
      return -1;
    }
};