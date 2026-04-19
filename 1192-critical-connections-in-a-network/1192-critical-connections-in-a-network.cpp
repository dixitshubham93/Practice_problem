class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& tim,
             vector<int>& early, vector<int>& visited,
             vector<vector<int>>& bridge){
        visited[node] = 1;
        tim[node] = early[node] = timer;
        timer++;
        for (int child : adj[node]) {
            if (child == parent)
                continue;
            if (!visited[child]){
                dfs(child, node, adj, tim, early, visited, bridge);
                early[node] = min(early[node], early[child]);
                if (tim[node] < early[child]) {
                    bridge.push_back({node, child});
                }
            } else {
                early[node] = min(early[node], early[child]);
            }
        }
        return;
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n);
        vector<int> tim(n);
        vector<int> early(n);
        vector<vector<int>> bridge;
        dfs(0, -1, adj, early, tim, visited, bridge);
        return bridge;
    }
};