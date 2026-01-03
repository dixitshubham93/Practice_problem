class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<vector<vector<int>>>>arr;
    int solve(int n, int f, int s, int t){
        if (n == 0) return 1;   

        if(arr[n][f][s][t]!=-1)return arr[n][f][s][t];

        int ans = 0;

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
        return arr[n][f][s][t] = ans;
    }

    int numOfWays(int n) {
        arr.assign(n+1 , vector<vector<vector<int>>>(4,vector<vector<int>>(4,vector<int>(4,-1))));
        
        return solve(n, 0, 0, 0);
    }
};
