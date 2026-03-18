class Solution {
public:

    int countSubmatrices(vector<vector<int>>& grid, int k){

        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int l = i-1<0?0:grid[i-1][j];
                int r = j-1<0?0:grid[i][j-1];
                int s = i>0&&j>0?grid[i-1][j-1]:0;
                grid[i][j] += (l + r -s);
                if(grid[i][j]<=k){ans++;}
                else{
                    break;
                }
            }
        }
        return ans;

    }

};