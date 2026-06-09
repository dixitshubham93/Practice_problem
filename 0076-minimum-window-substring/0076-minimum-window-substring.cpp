class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> mp;

        int count = t.size();

        for(char c : t)
            mp[c]++;

        int L = 0;
        int idx = 0;
        int len = INT_MAX;

        for(int R = 0; R < s.size(); R++) {

            if(mp.count(s[R])) {
                mp[s[R]]--;

                if(mp[s[R]] >= 0)
                    count--;
            }

            while(count == 0) {

                if(R - L + 1 < len) {
                    len = R - L + 1;
                    idx = L;
                }

                if(mp.count(s[L])) {
                    mp[s[L]]++;

                    if(mp[s[L]] > 0)
                        count++;
                }

                L++;
            }
        }

        return len == INT_MAX ? "" : s.substr(idx, len);
    }
};