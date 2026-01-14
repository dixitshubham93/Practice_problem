class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        map<int, int> mp;
        for (auto &f : flowers) {
            mp[f[0]]++;
            mp[f[1] + 1]--;
        }

        vector<pair<int,int>> v;
        int flowercnt = 0;
        for (auto &[idx, delta] : mp) {
            flowercnt += delta;
            v.push_back({idx, flowercnt});
        }

        vector<int> ans;

        for (int t : people) {
            auto it = upper_bound(v.begin(), v.end(), make_pair(t, INT_MAX));

            if (it == v.begin()) {
                ans.push_back(0);
            } else {
                --it;
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};
