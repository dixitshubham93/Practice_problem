class Solution {
public:
   int minCost(int n, vector<vector<int>>& edges) {

    vector<vector<pair<int,int>>> adj(n);
    for (auto &e : edges) {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], 2 * e[2]});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    vector<int> dist(n, INT_MAX);

    dist[0] = 0;
    pq.push({0, 0}); 

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();


        if (d > dist[node]) continue;

        for (auto [next, wt] : adj[node]) {
            if (d + wt < dist[next]) {
                dist[next] = d + wt;
                pq.push({dist[next], next});
            }
        }
    }

    return dist[n - 1]==INT_MAX?-1:dist[n-1];
    }

};