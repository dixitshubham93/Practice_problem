class Solution {
public:
    int solve(vector<int>&histo , int k){
        int n = histo.size();
        int ans = 0;
        for(int i = 1;i<=k;i++){
            int count =0;
            for(int j = 0;j<n;j++){

                if(histo[j]>=i){
                    count++;
                }else{count=0;}

                if(count==i){
                    count--;
                    ans++;
                }
            }
        }
        
        return ans;
    }
    int countSquares(vector<vector<int>>& matrix) {
       
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int>histo(m,0);

        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){               
             if(matrix[i][j]==1){
                histo[j]++;
             }else{
                histo[j]=0;
             }
            }
            ans += solve(histo , i+1);
        }
      return ans;
    }
};