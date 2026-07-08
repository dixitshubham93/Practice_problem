class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<long long> prefixSum(n);
        vector<long long> prefixConcat(n);
        vector<int> prefixCnt(n);
        vector<long long> pow10(n + 1);

        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        long long sum = 0;
        long long concat = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {

            if (s[i] != '0') {
                int d = s[i] - '0';

                sum = (sum + d) % MOD;
                concat = (concat * 10 + d) % MOD;
                cnt++;
            }

            prefixSum[i] = sum;
            prefixConcat[i] = concat;
            prefixCnt[i] = cnt;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            long long digitSum = prefixSum[r];
            if (l)
                digitSum = (digitSum - prefixSum[l - 1] + MOD) % MOD;

            int digits =
                prefixCnt[r] - (l ? prefixCnt[l - 1] : 0);

            long long concatValue = prefixConcat[r];

            if (l) {
                concatValue =
                    (concatValue -
                     prefixConcat[l - 1] * pow10[digits] % MOD +
                     MOD) %
                    MOD;
            }

            ans.push_back((digitSum * concatValue) % MOD);
        }

        return ans;
    }
};