class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);

        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
            inDegree[it[1]]++;
        }

        vector<long long>val(values.begin(), values.end());

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (inDegree[i]<=1) {
                q.push(i);
            }
        }
        int components = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            inDegree[curr]--;

            long long addVal = val[curr] % k == 0 ? 0 : val[curr];
            val[curr] = addVal;
            if (addVal == 0) {
                components++;
            }

            for (int it : adj[curr]) {
                if (inDegree[it]) {
                    inDegree[it]--;
                    val[it] += addVal;
                    if(inDegree[it]==1){
                    q.push(it);
                    }
                }
            }
        }

        return components;
    }
};