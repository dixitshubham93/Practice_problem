class DSU {
public:
    vector<int> size;
    vector<int> parent;
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a, int b) {
        int roota = find(a);
        int rootb = find(b);

        if (roota == rootb)
            return;
        if (size[roota] >= size[rootb]) {
            size[roota] += size[rootb];
            parent[rootb] = roota;
        } else {
            size[rootb] += size[roota];
            parent[roota] = rootb;
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        if (n == 1)
            return {true};
        DSU* dsu = new DSU(n);
        for (int i = 1; i < n; i++) {
            if (abs(nums[i - 1] - nums[i]) <= maxDiff) {
                dsu->Union(i, i - 1);
            }
        }
        vector<bool> ans;
        for (auto& it : queries) {
            if (dsu->find(it[0]) == dsu->find(it[1])) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};