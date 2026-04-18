class Solution {
public:
    vector<int>parent;
    vector<int>size;
    void DSU(int x){
        size.assign(x , 1);
        parent.assign(x , 0);
        for(int i = 0;i<x;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x , int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx==rooty)return ;
        if(size[rootx]>=size[rooty]){
            parent[rooty] = rootx;
            size[rootx] += size[rooty]; 
        }else{
            parent[rootx] = rooty;
            size[rooty] += size[rootx]; 
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string , int>mp;

        int n = accounts.size();
        DSU(n);
        for(int i = 0;i<n;i++){
            int m = accounts[i].size();
            for(int j = 1;j<m;j++){
                if(mp.count(accounts[i][j])>0){
                    Union(mp[accounts[i][j]],i );
                }else{
                  mp[accounts[i][j]] = i; 
                }
            }
        }
        vector<vector<string>>temp(n);
        for(auto& it : mp){
         int node = find(it.second);
         temp[node].push_back(it.first);
        }
        vector<vector<string>>ans;
         for(int i = 0;i<n;i++){
        if(temp[i].size()==0){continue;}
        sort(temp[i].begin() , temp[i].end());
        temp[i].insert(temp[i].begin() , accounts[i][0]);
        ans.push_back(temp[i]);
        }
        return ans;
    }
};