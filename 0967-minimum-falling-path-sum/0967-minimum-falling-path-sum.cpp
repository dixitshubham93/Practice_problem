class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix){
        int raw = matrix.size();
        int col = matrix[0].size();
        int ans = INT_MAX;
        if(raw==1){
            int e =INT_MAX;
            for(int i=0;i<col;i++){
              e = min(e,matrix[0][i]);
            }
            return e;
        }
        for(int i = 1;i<raw;i++){
            for(int j = 0;j<col;j++){
                int ele = INT_MAX;
                for(int k = max(j-1,0);k<=min(col-1,j+1);k++){
                    ele = min( ele,matrix[i-1][k]);
                }     
                matrix[i][j]+=ele;   
                if(i==raw-1){
                    ans = min(ans , matrix[i][j]);
                } 
            }
        }
       return ans;
    }
};