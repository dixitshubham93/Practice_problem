class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<int, vector<int>> mp;
        int prefix = 0;
        int n = s.size();
        int ans = 0;
        mp[0].push_back(-1);
        int one = 0;
        int zero = 0;
        vector<int> preone(n);
        vector<int> prezero(n);

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                preone[i] = preone[i - 1];
                prezero[i] = prezero[i - 1];
            }

            if (s[i] == '0') {
                prezero[i]++;
                zero++;
            } else {
                preone[i]++;
                one++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                prefix--;
            } else {
                prefix++;
            }

            if (mp.count(prefix)) {
                ans = max(ans, i - mp[prefix][0]);
            }

            if (mp.count(prefix - 2)) {
                for (int j = 0; j < mp[prefix - 2].size(); j++) {
                    int idx = mp[prefix - 2][j];

                    int zeroinside = prezero[i] - (idx >= 0 ? prezero[idx] : 0);
                    int zerooutside = zero - zeroinside;

                    if (zerooutside > 0) {
                        ans = max(ans, i - mp[prefix - 2][j]);
                        break;
                    }
                }
            }
            if (mp.count(prefix + 2)) {
                for (int j = 0; j < mp[prefix + 2].size(); j++) {
                    int idx = mp[prefix + 2][j];
                    int oneinside = preone[i] - (idx >= 0 ? preone[idx] : 0);
                    int oneoutside = one - oneinside;
                    if (oneoutside > 0) {
                        ans = max(ans, i - mp[prefix + 2][j]);
                        break;
                    }
                }
            }
            mp[prefix].push_back(i);
        }
        return ans;
    }
};