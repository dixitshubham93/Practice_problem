class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    unordered_map<int , set<int>>mp;
    int n = nums.size();
    for(int i = 0;i<n;i++){
        mp[nums[i]].insert(i);}
    
    int m = queries.size();
    vector<int>ans(m);

    for(int i =0;i<m;i++){
        auto& it = mp[nums[queries[i]]];
        int mn = INT_MAX;
        auto temp = it.find(queries[i]);
        int sz = it.size();
        if(sz==1){ans[i] = -1;
        continue;}     
        auto nxt = next(temp);
        if (nxt == it.end()) nxt = it.begin();
        int d1 = abs(*temp - *nxt);
        mn = min(mn, min(d1 , n-d1));

        auto prv = (temp == it.begin()) ? prev(it.end()) : prev(temp);
        int d2 = abs(*temp - *prv);
        mn = min(mn, min(d2 , n-d2));
        ans[i] = mn;
    }
     return ans;
    }
};