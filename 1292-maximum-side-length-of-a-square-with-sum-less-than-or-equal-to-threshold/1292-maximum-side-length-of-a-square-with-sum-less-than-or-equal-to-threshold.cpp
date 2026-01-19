class Solution {
public:
    int getSum(vector<vector<int>>& pref, int r, int c, int side) {
        int r1 = r - side + 1;
        int c1 = c - side + 1;

        int res = pref[r][c];
        if (r1 > 0) res -= pref[r1 - 1][c];
        if (c1 > 0) res -= pref[r][c1 - 1];
        if (r1 > 0 && c1 > 0) res += pref[r1 - 1][c1 - 1];

        return res;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                mat[i][j] += mat[i][j - 1];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] += mat[i - 1][j];
            }
        }

        for (int side = min(n, m); side >= 1; side--) {
            for (int i = side - 1; i < n; i++) {
                for (int j = side - 1; j < m; j++) {
                    if (getSum(mat, i, j, side) <= threshold) {
                        return side;
                    }
                }
            }
        }
        return 0;
    }
};
