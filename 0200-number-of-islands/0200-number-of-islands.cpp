class Solution {
public:
    void bfs(pair<int , int>source,vector<vector<bool>>&visited ,vector<vector<char>>& grid){
        queue<pair<int , int>>q;
        int dr[4] = {0 , 0 , -1 , 1};
        int dc[4] = {1 , -1 , 0 , 0};
        
        visited[source.first][source.second] = true;
        q.push(source);
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
          auto [x , y] = q.front();
          q.pop();
          for(int i = 0;i<4;i++){
            int newx = x + dr[i];
            int newy = y + dc[i];
            if(newx<0||newx>=n||newy<0||newy>=m){continue;}
            if(!visited[newx][newy]&&grid[newx][newy]=='1'){
                q.push({newx , newy});
                visited[newx][newy] = true;
            }
          }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n , vector<bool>(m ,false));
        int ans  =0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]=='1'){
                  bfs({i , j} , visited , grid);
                  ans++;
                }
            }
        }
        return ans;
    }
};