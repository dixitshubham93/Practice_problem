class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        vector<int> rank(n);
        int currentrank = 1;
        for (int i = 0; i < n; i++) {
            if (mp.count(temp[i]) == 0) {
                mp[temp[i]] = currentrank;
                currentrank++;
            }
        }
        for (int i = 0; i < n; i++) {
            rank[i] = mp[arr[i]];
        }
        return rank;
    }
};