class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int , int>>>adj(n);

        for(auto& it : flights){
            adj[it[0]].push_back({it[1] , it[2]});
        }

        vector<int>price(n , INT_MAX);
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<>>q;
        q.push({0 , {0 , src}});
        price[src] = 0;
        while(!q.empty()){
            auto[stops , temp] = q.top();
            auto[curr_price , parent] = temp;
            q.pop();
            if(stops==k+1){continue;}         
            for(auto[child , d_p_c] : adj[parent]){
                if(curr_price!=INT_MAX&&curr_price+d_p_c<price[child]){
                    price[child] = curr_price+d_p_c;
                    q.push({stops+1 , {price[child] , child}});
                }
            }
        }
     return price[dst]==INT_MAX?-1:price[dst];
    }
};