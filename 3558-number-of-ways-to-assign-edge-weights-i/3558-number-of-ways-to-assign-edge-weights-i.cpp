class Solution {
public:
    int MOD = 1e9+7;
    int solve(vector<vector<int>>&adj , int root , vector<int>&visited){

        visited[root] = 1;
        int ans = 0;

        for(auto child : adj[root]){
          if(!visited[child]){
            ans = max(ans , 1 + solve(adj , child , visited));
          }  
        }
        return ans;
    }
    long long getpower(int n ){
        if(n==0)return 1;

        long long ans = getpower(n/2)%MOD;
        ans = (ans*ans)%MOD;
        if(n%2==1){
            ans = (ans*2)%MOD;
        }
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
       int n = edges.size()+3;
        vector<vector<int>>adj(n);
        vector<int>visited(n);

        for(auto&it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int mx = solve(adj , 1 , visited);
        return getpower(mx-1);
    }
};