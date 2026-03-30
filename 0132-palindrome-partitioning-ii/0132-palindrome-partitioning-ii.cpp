class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> pp;
    

    bool isPalin(string &s , int front , int end) {

        while (front <= end) {
            if (s[front] != s[end]) return false;
            front++;
            end--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        pp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
       for(int i=0;i<n;i++)
       {
        for(int j =0;j<n;j++)
        {
            pp[i][j] = isPalin(s,i,j);
        }
       }
        
        for (int i = 0; i < n; i++) {
            if (pp[i][n - 1]) {
                dp[i][n - 1] = 0;
            } else {
                dp[i][n - 1] = n - 1 - i;
            }
        }

        // Bottom-up DP: i = front, j = end
        for (int front = n - 1; front >= 0; front--) {
            for (int end = n - 2; end >= front; end--) {
                int ans = INT_MAX;

                if (pp[front][end]) {
                    int f = end + 1;
                    int e = f;
                    if (e >= n) {
                        ans = 0;
                    } else {
                        ans = 1 + dp[f][e];
                    }
                }

                ans = min(ans, dp[front][end + 1]);
                dp[front][end] = ans;
            }
        }

        return dp[0][0];
    }
};
