class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[201][201][201];

    int Solve(int i, vector<int>& nums, int gcd1, int gcd2) {
        if (i == nums.size()) {
            if (gcd1 == 0 || gcd2 == 0)
                return 0;
            return gcd1 == gcd2 ? 1 : 0;
        }
        if (dp[i][gcd1][gcd2] != -1)
            return dp[i][gcd1][gcd2];
        int ans = 0;
        ans = (ans % MOD + Solve(i + 1, nums, gcd(gcd1, nums[i]), gcd2) % MOD) %
              MOD;
        ans = (ans % MOD + Solve(i + 1, nums, gcd1, gcd(gcd2, nums[i])) % MOD) %
              MOD;
        ans = (ans % MOD + Solve(i + 1, nums, gcd1, gcd2) % MOD) % MOD;
        return dp[i][gcd1][gcd2] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return Solve(0, nums, 0, 0);
    }
};