class Solution {
public:
    static const int MOD = 1e9 + 7;
    int arr[5001][4][4][4];

    Solution() {
        memset(arr, -1, sizeof(arr)); 
    }

    int solve(int n, int f, int s, int t) {
        if (n == 0) return 1;

        int &res = arr[n][f][s][t];
        if (res != -1) return res;

        long long ans = 0;

        if (f == 0) {
            for (int i = 1; i <= 3; i++) {
                for (int k = 1; k <= 3; k++) {
                    for (int j = 1; j <= 3; j++) {
                        if (j != i && j != k) {
                            ans = (ans + solve(n - 1, i, j, k)) % MOD;
                        }
                    }
                }
            }
        } else {
            for (int i = 1; i <= 3; i++) {
                if (i != f) {
                    for (int k = 1; k <= 3; k++) {
                        if (k != t) {
                            for (int j = 1; j <= 3; j++) {
                                if (j != i && j != k && j != s) {
                                    ans = (ans + solve(n - 1, i, j, k)) % MOD;
                                }
                            }
                        }
                    }
                }
            }
        }
        return res = ans;
    }

    int numOfWays(int n) {
        return solve(n, 0, 0, 0);
    }
};
