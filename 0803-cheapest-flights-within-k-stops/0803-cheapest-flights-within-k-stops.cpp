class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>>> adj(n);
        for(auto& vec : flights){
            adj[vec[0]].push_back({vec[1], vec[2]});
        }

        vector<vector<int>> price(n, vector<int>(k+2, INT_MAX));
        price[src][0] = 0;

        priority_queue<pair<int , pair<int , int>>, 
                       vector<pair<int , pair<int , int>>>, 
                       greater<pair<int , pair<int , int>>>> q;

        q.push({0, {src, 0}});

        while(!q.empty()){
            int node = q.top().second.first;
            int tkt_p = q.top().first;
            int k_count = q.top().second.second;
            q.pop();

            if(node == dst) return tkt_p;   

            if(k_count == k+1) continue;   

            for(auto& adjecent : adj[node]){
                int city = adjecent.first;
                int tkt_p_c  = adjecent.second;
                int newCost = tkt_p + tkt_p_c;

                if(newCost < price[city][k_count+1]){
                    price[city][k_count+1] = newCost;
                    q.push({newCost, {city, k_count+1}});
                }
            }
        }
        return -1;
    }
};
