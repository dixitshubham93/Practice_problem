class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<int>&visited , int node,vector<int>&path ){
        visited[node] = 1;
        path[node] = 1;
        for(auto& child : adj[node]){
            if(path[child]==1){return false;}
           if(!visited[child]){
            if(!dfs(adj , visited , child , path)){return false;}
           }
        }
        path[node] = 0;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>visited(n);
        vector<int>path(n);

        vector<vector<int>>adj(n);
        for(auto&it : pre){
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0;i<n;i++){
            if(visited[i]==0){         
                if(!dfs(adj , visited , i , path)){return false;}
            }
        }
    return true;
    }
};