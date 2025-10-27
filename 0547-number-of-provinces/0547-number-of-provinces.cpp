class Solution {
public:
    void dfs(vector<int>& visited, vector<vector<int>>& adj, int index) {
        visited[index] = 1;
        for (int adjecents : adj[index]) {
            if (!visited[adjecents]) {
                dfs(visited, adj, adjecents);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(visited, adj, i);
            }
        }
        return count;
    }
};