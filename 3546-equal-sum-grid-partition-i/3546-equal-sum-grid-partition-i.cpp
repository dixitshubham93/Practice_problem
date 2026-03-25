class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>>Rect_rec(n , vector<long long>(m));
        long long sum = 0;
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                long long upper_rec = i==0?0:Rect_rec[i-1][j];
                long long left_rec = j==0?0:Rect_rec[i][j-1];
                long long  inter_rec = i!=0&&j!=0?Rect_rec[i-1][j-1]:0;
                Rect_rec[i][j] = upper_rec+left_rec-inter_rec+grid[i][j];
                sum += grid[i][j];
            }
        }
        if(sum%2!=0){return false;}

        long long target = sum/2;

        for(int i = 0;i<m-1;i++){
            if(Rect_rec[n-1][i]==target){return true;}
        }
        for(int i = 0;i<n-1;i++){
            if(Rect_rec[i][m-1]==target){return true;}
        }
      return false;
    }
};