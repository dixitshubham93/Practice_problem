class Solution {
public:
    vector<int> size, parent;

    void dsu(int n) {
        size.assign(n + 1, 1);
        parent.assign(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) return;
        if (size[rootx] > size[rooty]) {
            parent[rooty] = rootx;
            size[rootx] += size[rooty];
        } else {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        dsu(c);  

        unordered_map<int, set<int>> mp;
        vector<vector<int>> adj(c+1);

        for (auto& it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            unionSet(u, v);
        }
        for(int i=1;i<=c;i++){
            mp[find(i)].insert(i);
        }

        vector<bool> marker(c, true);
        vector<int> ans;

        for (auto& it : queries) {
            if (it[0] == 2) {
                marker[it[1]] = false;
                mp[find(it[1])].erase(it[1]);
            } else {
                if (marker[it[1]]) {
                    ans.push_back(it[1]);
                } else {
                    int root = find(it[1]);
                    if (mp[root].empty()) ans.push_back(-1); 
                    else ans.push_back(*mp[root].begin());
                }
            }
        }

        return ans;
    }
};
