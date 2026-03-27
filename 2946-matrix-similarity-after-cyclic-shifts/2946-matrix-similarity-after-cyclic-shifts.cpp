class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {

        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            vector<int> arr(m);

            for (int j = 0; j < m; j++) {
                int ind;

                if (i % 2 == 0) {
                  
                    ind = (j + k) % m;
                } else {
                   
                    ind = (j - (k%m) + m) % m;
                }

                arr[ind] = mat[i][j];
            }

            if (mat[i] != arr) return false;
        }

        return true;
    }
};