class Solution {
public:
    int mod = 2*1e9;
    int uniquePathsWithObstacles(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(grid[n-1][m-1]==1)return 0;
        vector<vector<int>>dp(n , vector<int>(m , 0));
        dp[n-1][m-1] = 1;

        for(int r = n-1;r>=0;r--){
            for(int c = m-1;c>=0;c--){
                if(r==n-1&&c==m-1)continue;
                if(grid[r][c]==1){dp[r][c]= 0;
                continue;}
                dp[r][c] +=  (int)((r!=(n-1)?1LL*dp[r+1][c]:0)%mod + (c!=(m-1)?1LL*dp[r][c+1]:0)%mod)%mod;
            }
        }
        return dp[0][0];
    }
};