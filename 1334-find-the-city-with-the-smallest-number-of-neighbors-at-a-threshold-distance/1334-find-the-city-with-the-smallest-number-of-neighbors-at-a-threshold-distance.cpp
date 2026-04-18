class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));

        for (auto& it : edges) {
            mat[it[0]][it[1]] = it[2];
            mat[it[1]][it[0]] = it[2];
            mat[it[0]][it[0]] = 0;
            mat[it[1]][it[1]] = 0;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX) {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }
        pair<int , int>ans= {INT_MAX, -1};
        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < n; j++) {
                if(mat[i][j]<=distanceThreshold){
                    temp++;
                }
            }
            if(ans.first>temp){
                ans.first = temp;
                ans.second = i;
            }else if(ans.first == temp){
                ans.second = max(ans.second , i);
            }
        }
        return ans.second;
    }
};