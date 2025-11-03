class Solution {
public:
    vector<vector<vector<int>>>dp;
    int helper(vector<vector<int>>& grid , int depth ,int r1 , int r2){
        if(depth==grid.size()){
            return 0;
        }
          if(dp[depth][r1][r2]!=-1)return dp[depth][r1][r2];
          int n = grid[0].size();
          int ans=0;
          for(int i=-1;i<=1;i++){
            for(int j =-1;j<=1;j++){
                if(i+r1>=0&&i+r1<n&&j+r2>=0&&j+r2<n){
                    ans = max(ans , helper(grid , depth+1 ,i+r1 , j+r2));
                }
            }
           }
        if(r1==r2){
        return dp[depth][r1][r2] = ans + grid[depth][r1];
        }
    
      return dp[depth][r1][r2] = ans + grid[depth][r1]+ grid[depth][r2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        dp.assign(m , vector<vector<int>>(n , vector<int>(n , -1)));

        return helper(grid , 0 , 0 , n-1);
    }
};