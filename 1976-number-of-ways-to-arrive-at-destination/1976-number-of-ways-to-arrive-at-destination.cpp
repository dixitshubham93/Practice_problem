class Solution {
public:
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int ,int>>>adj(n);

        for(auto it : roads){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        vector<long long>dist(n+1 , LLONG_MAX);
        vector<long long>ways(n+1 , 0);

        priority_queue<pair<long long , long long> , vector<pair<long long , long long>> , greater<pair<long , long>>>pq;
        pq.push({0 , 0});
        ways[0] = 1;
        dist[0] = 0;

        while(!pq.empty()){
            auto [cur , node] = pq.top();
            pq.pop();

            if(cur>dist[node])continue;
            
            for(auto child : adj[node]){
                long long  time = 1ll*cur + 1ll*child.second;
                int ch = child.first;
                if(dist[ch] == time){
                ways[ch] = (ways[ch]%mod+ways[node]%mod)%mod;
                }else if(dist[ch] > time){
                  dist[ch] = time;
                  ways[ch] = ways[node]%mod;
                  pq.push({time , ch});
                }
            }
        }
        return ways[n-1];
    }
};