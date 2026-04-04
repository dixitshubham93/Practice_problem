class Solution {
public:
    int nodes;
    int dfs(int node, vector<vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;
        nodes++;
        int count = 0;
        for (int neighbor : adj[node]){
            count++;
            if (!visited[neighbor]) {
                
             count +=dfs(neighbor, adj, visited);
            }
        }
        return count;
    }

   

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> visited(n, 0);

        int ans = 0;
        for (int i = 0;i<n;i++){
            int edgeCount = 0;
            nodes=0;
           if(visited[i]==0){
            edgeCount = dfs(i , adj , visited);          
            edgeCount /= 2;  
            if (nodes*(nodes-1)/2 == edgeCount){
                ans++;
            }
          }
        }
        return ans;
    }
};

