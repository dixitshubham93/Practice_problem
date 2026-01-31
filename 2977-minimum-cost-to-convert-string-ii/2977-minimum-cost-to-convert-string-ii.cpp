class Solution {
public:
    typedef long long ll;
    typedef pair<ll, string> P;
    const ll INF = 1e18;
    unordered_map<string , vector<P>> mp;
    vector<ll> dp;
    unordered_set<int> lengths;
    string sourceStr;
    string targetStr;



    ll Dij(string start , string end){

        unordered_map<string , ll> dist;
        priority_queue<P , vector<P> , greater<>> q;

        dist[start] = 0;
        q.push({0 , start});

        while(!q.empty()){

            auto [cur_cost, cur_node] = q.top();
            q.pop();

            if(cur_node == end)
                return cur_cost;

            
            if(cur_cost > dist[cur_node]) continue;

            if(!mp.count(cur_node)) continue;

            for(auto &adj : mp[cur_node]){

                ll next_cost = cur_cost + adj.first;
                string next = adj.second;

                if(!dist.count(next) || next_cost < dist[next]){

                    dist[next] = next_cost;
                    q.push({next_cost , next});
                }
            }
        }

        return INF;
    }

    ll solve(int idx){

        if(idx >= sourceStr.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        ll minCost = INF;

        
        if(sourceStr[idx] == targetStr[idx])
            minCost = solve(idx+1);

        for(int l : lengths){

            if(idx + l > sourceStr.size())
                continue;

            string s = sourceStr.substr(idx , l);
            string t = targetStr.substr(idx , l);

            if(!mp.count(s))
                continue;

            ll cost = Dij(s , t);

            if(cost == INF)
                continue;

            ll next = solve(idx + l);

            if(next != INF)
                minCost = min(minCost , cost + next);
        }

        return dp[idx] = minCost;
    }

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        sourceStr = source;
        targetStr = target;

        dp.assign(source.size()+1 , -1);

        for(int i = 0;i<original.size();i++){

            mp[original[i]].push_back({(ll)cost[i] , changed[i]});
            lengths.insert(original[i].size());
        }

        ll ans = solve(0);

        return ans == INF ? -1 : ans;
    }
};
