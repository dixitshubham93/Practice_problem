class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int>time(n+1 , INT_MAX);
        time[0] = 0;
        time[k] = 0;
        vector<vector<pair<int , int>>>adj(n+1);
        for(auto& vec : times){
            adj[vec[0]].push_back({vec[1],vec[2]});
        }
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<>>q;
        q.push({0 , k});
        while(!q.empty()){
            int parent = q.top().second;
            int p_time = q.top().first;
            q.pop();
            for(auto& child_node : adj[parent]){
                int child = child_node.first ; 
                int c_time = child_node.second;
                int newTime = c_time + p_time;
                if(newTime < time[child]){
                    time[child] = newTime ; 
                    q.push({newTime , child});
                    }
            }
        }
         int time_to_all = INT_MIN;
         for(int i=0;i<=n;i++){
            time_to_all = max(time[i] , time_to_all);
         }
         return time_to_all==INT_MAX?-1:time_to_all;
    }
};