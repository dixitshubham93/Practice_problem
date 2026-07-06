class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int , int>>>adj(n+2);

        for(auto& it : roads){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        int ans = INT_MAX;
        queue<int>q;
        vector<bool>visited(n+1 , false);
        q.push(1);
        visited[1] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();        
            for(auto& it : adj[node]){
                int edge = it.second;
                int child = it.first;
                ans = min(ans , edge);
                if(!visited[child]){
                    visited[child] = true;
                    q.push(child);
                }
            }
        }
        return ans;
    }
};