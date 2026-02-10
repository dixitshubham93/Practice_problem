class Solution {
public:
    int n , m ;
    int bfs(int i , int j , vector<vector<int>>& grid , vector<vector<bool>>&marker ){
       int dr[4] = {0 , 0 , -1 , 1};
       int dc[4] = {-1 , 1 , 0 , 0};
       queue<pair<int , int>>q;
       q.push({i , j});
       int ans = 1;
       marker[i][j] = true;
       while(!q.empty()){
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
        for(int it = 0;it<4;it++){
        int newi = x + dr[it];
        int newj = y + dc[it];
        if(newi<0||newi>=n||newj<0||newj>=m){continue;}
        if(!marker[newi][newj]&&grid[newi][newj]){
            q.push({newi , newj});
            marker[newi][newj] = true;
            ans++;
        }
       }
       }
       return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();

        vector<vector<bool>>marker( n , vector<bool>(m , false));
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
            if(!marker[i][j]&&grid[i][j]){
               ans = max(bfs(i , j , grid , marker) , ans);
             }
            }
        }
       return ans;
    }
};