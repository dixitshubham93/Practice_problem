class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> adj(n);

        for(auto &r : roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> dis(n, LLONG_MAX);
        vector<long long> freq(n, 0);

        priority_queue<
            pair<long long,long long>,
            vector<pair<long long,long long>>,
            greater<>
        > q;

        dis[0] = 0;
        freq[0] = 1;

        q.push({0, 0});

        while(!q.empty()){
            auto [time, node] = q.top();
            q.pop();

            if(time > dis[node]) continue;

            for(auto &[child, wt] : adj[node]){
                long long newtime = time + wt;

                if(newtime < dis[child]){
                    dis[child] = newtime;
                    freq[child] = freq[node];
                    q.push({newtime, child});
                }
                else if(newtime == dis[child]){
                    freq[child] = (freq[child] + freq[node]) % MOD;
                }
            }
        }

        return freq[n-1];
    }
};