class Solution {
public:
    void markdfs(vector<vector<int>>& grid , int row , int col ){
      int dr[4] = {0 , 0 , 1 , -1};
      int dc[4] = {-1 , 1 , 0 , 0};
      int n = grid.size();
      int m = grid[0].size();
      if(grid[row][col]==0){grid[row][col]=2;}
      
      for(int i = 0;i<4;i++){
        int newr = dr[i] + row;
        int newc = dc[i] + col;
        if(newr<0||newr>=n||newc<0||newc>=m||grid[newr][newc]!=0){
          continue;
        }
        grid[newr][newc] = 2;
        markdfs(grid , newr , newc);
      }
      return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0;i<n;i++){
            if(grid[i][m-1]==0){
                markdfs(grid , i , m-1);
            }
            if(grid[i][0]==0){
                markdfs(grid , i , 0);
            }
        }

        for(int i = 0;i<m;i++){
            if(grid[0][i]==0){
                
                markdfs(grid , 0 , i);
            }
            if(grid[n-1][i]==0){
                markdfs(grid , n-1 , i);
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==0){
                  ans++;
                  markdfs(grid , i , j);
                }
            }
        }
        return ans;
    }
};