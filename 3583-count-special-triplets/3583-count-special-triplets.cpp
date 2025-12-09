class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        // value -> list of indices where this value appears
        unordered_map<long long, vector<int>> pos;
        pos.reserve(n * 2);

        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }

        long long ans = 0;

        for (int j = 0; j < n; ++j) {
            long long h = nums[j];      // middle value
            long long f = 2 * h;        // we need nums[i] = nums[k] = f

            auto it = pos.find(f);
            if (it == pos.end()) continue;   // no such value, skip

            const vector<int>& v = it->second;  // all indices where nums[x] == f

            // v is sorted because we pushed indices in increasing order

            // count indices < j  → left
            int leftCnt = int(lower_bound(v.begin(), v.end(), j) - v.begin());

            // count indices > j  → right
            int rightCnt = int(v.end() - upper_bound(v.begin(), v.end(), j));

            long long add = 1LL * leftCnt * rightCnt;
            ans = (ans + add) % MOD;
        }

        return (int)ans;
    }
};
