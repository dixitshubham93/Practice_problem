class Solution {
public:
  int solve(vector<int>&histo ){
        int m = histo.size();
        vector<int>temp(histo.begin() , histo.end());
        sort(temp.begin() , temp.end());
        int mx = 0;
        for(int i = 0;i<m;i++){
            mx = max(mx , temp[i]*(m-i));
        }
        return mx;
    }

    int largestSubmatrix(vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        int mx = 0;
        vector<int>histo(m);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j]==1){
                    histo[j]++;
                }else{
                    histo[j] = 0;
                }
            }
            mx = max(mx , solve(histo));
        }
      return mx;
    }
};