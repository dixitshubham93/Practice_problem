class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;

        int count = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            // found a special substring
            if (count == 0) {
                // recursively process inner part
                string inner =
                    makeLargestSpecial(s.substr(start + 1, i - start - 1));

                parts.push_back("1" + inner + "0");
                start = i + 1;
            }
        }

        // sort descending for largest lexicographic result
        sort(parts.rbegin(), parts.rend());

        string ans = "";
        for (auto &p : parts) ans += p;

        return ans;
    }
};