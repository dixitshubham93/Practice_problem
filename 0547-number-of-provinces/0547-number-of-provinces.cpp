class Solution {
public:
    void dfs(vector<vector<int>>& adj , vector<int>&visited , int idx){
       visited[idx] = 1;
       for(int i : adj[idx]){
        if(visited[i]==0){
            dfs(adj  , visited , i);
        }
       }
       return ;
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

        vector<int>visited(n ,0);
        int count = 0;
        for(int i = 0;i<n;i++){
            if(visited[i]==0){
                count++;
                dfs(adj , visited , i);
            }
        }
        return count;
    }
};