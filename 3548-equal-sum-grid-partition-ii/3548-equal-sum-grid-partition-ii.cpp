class Solution {
public:
    bool horizontalCheck(vector<vector<int>>& grid , long long sum){
        int n = grid.size();
        int m = grid[0].size();
        unordered_set<long long>st;
        long long top = 0;
        for(int i = 0;i<n-1;i++){
            for(int j = 0;j<m;j++){
                top += grid[i][j];
                st.insert((long long)grid[i][j]);
            }
            long long bottom = sum-top;
            long long diff = top - bottom;
            if(diff==(long long)0)return true;
            else if(diff==(long long)grid[0][0]||diff==(long long)grid[0][m-1]){return true;}
            else if(i>0&&m>1&&st.count(diff)){return true;}
            else if(m==1&&diff==(long long)grid[i][0]){return true;}
        }
      return false;
    }
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> result(m, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                sum += grid[i][j];
            }
        }
        if(horizontalCheck(grid , sum)){
            return true;
        }
        auto trans =  transpose(grid);
         if(horizontalCheck(trans , sum)){
            return true;
        }
        reverse(grid.begin() , grid.end());
        if(horizontalCheck(grid , sum)){
            return true;
        }
        reverse(trans.begin() , trans.end());
        if(horizontalCheck(trans , sum)){
            return true;
        }
       return false;
    }
};