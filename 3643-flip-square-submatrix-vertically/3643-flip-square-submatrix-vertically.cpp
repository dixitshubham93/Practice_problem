class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k){
        int n = grid.size();
        int m = grid[0].size();
        int end_row  = min(x+k-1 , n-1);
        int end_col =  min(y+k-1,  m-1);

        while(x<end_row){
            for(int i = y;i<=end_col;i++){
                swap(grid[x][i] , grid[end_row][i]);
            }
            x++;
            end_row--;
        }
        return grid;
    }
};