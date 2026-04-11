class Solution {
public:
    vector<int>findOrder(int n, vector<vector<int>>& pre){
        vector<int>ans;
        vector<int>degree(n);
        vector<vector<int>>adj(n);
        for(auto& it : pre){
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
        }
        queue<int>q;
        for(int i = 0;i<n;i++){
            if(degree[i]==0){
               q.push(i);
            }
        }
        while(!q.empty()){
          int node = q.front();
          ans.push_back(node);
          q.pop();
          for(int child : adj[node]){
            if(degree[child]>0){
                degree[child]--;
                if(degree[child]==0){
                    q.push(child);
                }
            }     
          }
        }
        if(ans.size()!=n){return {};}
        return ans;
    }
};