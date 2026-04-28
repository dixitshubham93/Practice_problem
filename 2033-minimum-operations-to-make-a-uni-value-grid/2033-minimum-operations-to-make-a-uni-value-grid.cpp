class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>temp;
        int n = grid.size();
        int m = grid[0].size();
        int rem  = grid[0][0]%x;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                    temp.push_back(grid[i][j]);
                    if(grid[i][j]%x!=rem){return -1;}       
            }
        }
        sort(temp.begin() , temp.end());
        int u = temp.size();
        int target = temp[u/2];
        int ans = 0;
        for(int i =0;i<u;i++){
            ans += abs(target-temp[i])/x;
        }
       return ans;
    }
};