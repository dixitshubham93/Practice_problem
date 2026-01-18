class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c, int side) {
        int val = -1;

        for(int i = r; i < r + side; i++) {
            int temp = 0;
            for(int j = c; j < c + side; j++) {
                temp += grid[i][j];
            }
            if(val == -1) val = temp;
            else if(val != temp) return false;
        }

        for(int j = c; j < c + side; j++) {
            int temp = 0;
            for(int i = r; i < r + side; i++) {
                temp += grid[i][j];   
            }
            if(temp != val) return false;
        }

        int temp = 0;
        for(int i = r, j = c; i < r + side && j < c + side; i++, j++) {
            temp += grid[i][j];
        }
        if(temp != val) return false;

        temp = 0;
        for(int i = r, j = c + side - 1; i < r + side && j >= c; i++, j--) {
            temp += grid[i][j];
        }
        if(temp != val) return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int side = min(n, m); side >= 2; side--) {
            for(int i = 0; i + side <= n; i++) {     
                for(int j = 0; j + side <= m; j++) {  
                    if(isMagicSquare(grid, i, j, side)) {
                        return side;
                    }
                }
            }
        }
        return 1;
    }
};
