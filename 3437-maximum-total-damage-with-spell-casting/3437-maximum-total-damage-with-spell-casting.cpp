class Solution {
public:
    vector<long long> dp;

    long long solve(vector<long long>& v, int index, unordered_map<long long,long long>& mp) {
        if (index >= v.size()) return 0;
        if (dp[index] != -1) return dp[index];

        int temp = index + 1;
        while (temp < v.size() && v[temp] <= v[index] + 2) {
            temp++;
        }

        long long l = 1LL * v[index] * mp[v[index]];
        if (temp<v.size()&&v[temp] > v[index] + 2) {
            l +=  solve(v, temp, mp);
        }

        long long r = 0;
        if (temp != index + 1) {
            r = solve(v, index + 1, mp);
        }

        return dp[index] = max(l, r);
    }

    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long ,long long> mp;
        for (int x : power) mp[x]++;
        vector<long long> v;
        for (auto& it : mp) v.push_back(it.first);
        sort(v.begin(), v.end());
        dp.assign(v.size(), 1LL*-1);
        return solve(v, 0, mp);
    }
};
