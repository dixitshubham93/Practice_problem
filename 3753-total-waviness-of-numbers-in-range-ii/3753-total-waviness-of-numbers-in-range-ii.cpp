class Solution {
public:
    struct Node {
        long long cnt;
        long long wave;

        Node(long long c = 0, long long w = 0)
            : cnt(c), wave(w) {}
    };

    string s;

    Node dp[20][2][2][11][11];
    bool vis[20][2][2][11][11];

    Node dfs(int pos,
             int tight,
             int started,
             int prev1,
             int prev2) {

        if (pos == s.size()) {
            return Node(1, 0);
        }

        if (vis[pos][tight][started][prev1][prev2])
            return dp[pos][tight][started][prev1][prev2];

        vis[pos][tight][started][prev1][prev2] = true;

        Node ans;

        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {

            int ntight = tight && (d == limit);

            if (!started && d == 0) {

                Node child =
                    dfs(pos + 1,
                        ntight,
                        0,
                        10,
                        10);

                ans.cnt += child.cnt;
                ans.wave += child.wave;
            }
            else {

                if (!started) {

                    Node child =
                        dfs(pos + 1,
                            ntight,
                            1,
                            10,
                            d);

                    ans.cnt += child.cnt;
                    ans.wave += child.wave;
                }
                else {

                    int add = 0;

                    if (prev1 != 10) {

                        if ((prev2 > prev1 && prev2 > d) ||
                            (prev2 < prev1 && prev2 < d))
                            add = 1;
                    }

                    Node child =
                        dfs(pos + 1,
                            ntight,
                            1,
                            prev2,
                            d);

                    ans.cnt += child.cnt;

                    ans.wave +=
                        child.wave +
                        1LL * add * child.cnt;
                }
            }
        }

        return dp[pos][tight][started][prev1][prev2] = ans;
    }

    long long solve(long long x) {

        if (x < 0) return 0;

        s = to_string(x);

        memset(vis, 0, sizeof(vis));

        return dfs(0, 1, 0, 10, 10).wave;
    }

    long long totalWaviness(long long num1,
                            long long num2) {

        return solve(num2)
             - solve(num1 - 1);
    }
};