class Solution {
public:
    bool dfs(vector<vector<int>>& adj , vector<int>&topo , vector<int>& visited , int n ){
        visited[n] = 1;
        for(int child : adj[n]){
            if(visited[child]==0){
                if(dfs(adj , topo , visited , child)){return true;}
            }else if(visited[child]==1){return true;}
        }
        topo.push_back(n);
        visited[n] = 2;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int>topo;
        vector<vector<int>>adj(n);
        vector<int>visited(n,0);
        
        for(auto & it : p){
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i = 0;i<n;i++){
          if(visited[i]==0){
            if(dfs(adj , topo ,visited, i)){return {};}
          }
        }
        reverse(topo.begin() , topo.end());
        return topo;
    }
};