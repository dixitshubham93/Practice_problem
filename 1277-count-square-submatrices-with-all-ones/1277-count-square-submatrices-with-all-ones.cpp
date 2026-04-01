class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>dp = matrix;
        int n  = matrix.size();
        int m  = matrix[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j  =0;j<m;j++){
               if(dp[i][j]==1){
                  if(i==0||j==0){
                    ans++;
                    continue;
                  }
                  dp[i][j]+= min(dp[i-1][j] , min(dp[i][j-1] , dp[i-1][j-1]));
                  ans  += dp[i][j];
               }
            }
        }

       return ans;
    }
};