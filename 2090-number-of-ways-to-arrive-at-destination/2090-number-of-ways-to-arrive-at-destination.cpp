class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &vec : roads) {
            adj[vec[0]].push_back({vec[1], vec[2]});
            adj[vec[1]].push_back({vec[0], vec[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;  

            for (auto &edge : adj[node]) {
                int child = edge.first;
                long long newDist = d + edge.second;

                if (newDist < dist[child]) {
                    dist[child] = newDist;
                    ways[child] = ways[node];
                    pq.push({newDist, child});
                } else if (newDist == dist[child]) {
                    ways[child] = (ways[child] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};
