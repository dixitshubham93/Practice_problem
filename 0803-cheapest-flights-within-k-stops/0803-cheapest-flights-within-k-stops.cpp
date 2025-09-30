class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>>> adj(n);
        for(auto& vec : flights){
            adj[vec[0]].push_back({vec[1], vec[2]});
        }

        vector<int> price(n, INT_MAX);
        price[src] = 0;

        queue<pair<int,pair<int , int>>>q;

        q.push({0, {0, src}});

        while(!q.empty()){
            int stops = q.front().first;
            int tkt_p = q.front().second.first;
            int node = q.front().second.second;
            q.pop();
            if(stops == k+1) continue;   

            for(auto& adjecent : adj[node]){
                int city = adjecent.first;
                int tkt_p_c  = adjecent.second;
                int newCost = tkt_p + tkt_p_c;
                if(newCost < price[city]&&stops+1<=k+1){
                    price[city] = newCost;
                    q.push({stops+1, {newCost,city}});
                }
            }
        }
        if(price[dst]==INT_MAX)return -1;
        return price[dst];
    }
};
