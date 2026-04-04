class Solution {
public:
    bool isCyc(int v, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVis) {
        visited[v] = 1;
        pathVis[v] = 1;

        for (int nei : adj[v]) {
            if (!visited[nei]) {
                if (isCyc(nei, adj, visited, pathVis)) return true;
            }
            else if (pathVis[nei]) {
                return true;
            }
        }

        pathVis[v] = 0; 
        return false;
    }

    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for (auto edge : edges) {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(V, 0), pathVis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyc(i, adj, visited, pathVis)) return false;
            }
        }

        return true;
    }
};