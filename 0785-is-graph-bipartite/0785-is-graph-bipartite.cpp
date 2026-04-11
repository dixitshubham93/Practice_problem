class Solution {
public:
    bool bfs(int node ,vector<vector<int>>& graph , vector<int>& visited){
        queue<int>q;
        q.push(node);
        visited[node]=1;

        while(!q.empty()){
            int color = visited[q.front()];
            int parent = q.front();
            q.pop();
            for(int child : graph[parent]){
                if(visited[child]==color){
                    return false;
                }else if(visited[child]==0){
                    visited[child] = color==1?2:1;
                    q.push(child);
                }
            }
        }
      return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
     int n = graph.size();
     vector<int>visited(n);
     for(int i = 0;i<n;i++){
        if(visited[i]==0){
            if(!bfs(i , graph , visited)){return false;}
        }
     }
     return true;
    }
};