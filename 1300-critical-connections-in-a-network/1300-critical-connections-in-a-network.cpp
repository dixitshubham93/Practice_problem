class Solution {
public:
       int timer = 1;
    void dfs(int node , int parent , int tim[] , int low[] ,vector<vector<int>>&bridge , vector<int>&visited , vector<vector<int>>&adj ){
        visited[node] =1;
        tim[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it==parent)continue;
            if(!visited[it]){
               dfs(it , node , tim , low , bridge , visited, adj);
               low[node] = min(low[node] , low[it]);
               if(tim[node]<low[it]){
                bridge.push_back({node , it});
               }
            }else{
               low[node] = min(low[node] , low[it]);
            }
        }
       return; 
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto& edge : connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
         vector<int>visited(n , 0);
         int tim[n];
         int low[n];
          vector<vector<int>>bridge;
          dfs(0 , -1 , tim , low , bridge , visited , adj);
      return bridge;
    }
};