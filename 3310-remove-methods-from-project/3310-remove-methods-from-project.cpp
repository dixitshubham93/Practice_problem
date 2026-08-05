class Solution {
public:
    void mark(int k, vector<int>& visited, vector<vector<int>>& adj) {
        visited[k] = 2;
        for (auto it : adj[k]) {
            if (visited[it] == 0) {
                mark(it, visited, adj);
            }
        }
        return;
    }
    bool dfs(int k, vector<int>& visited, vector<vector<int>>& adj) {
        visited[k] = 1;
        for (auto it : adj[k]) {
            if (visited[it] == 0) {
                if(dfs(it, visited, adj))return true;
            } else if (visited[it] == 2) {
                return true;
            }
        }
        return false;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<int> visited(n, 0);
        vector<vector<int>> adj(n);

        for (auto& it : inv) {
            adj[it[0]].push_back(it[1]);
        }

        mark(k, visited, adj);
        bool ispossible = false;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
               if(dfs(i, visited, adj)){
                 ispossible = true;
                 break;
               }
            }
        }
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            if (ispossible||visited[i]==1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};