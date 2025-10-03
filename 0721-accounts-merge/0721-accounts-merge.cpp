class Solution {
public:
     vector<int>parent;
     vector<int>size;
     void disjoinset(int v){
        size.resize(v,1);
        parent.resize(v,0);
        for(int i=0;i<v;i++){
            parent[i] = i;
        }
     }
     int find(int x){
        if(parent[x]==x)return x;
        return parent[x] = find(parent[x]);
     }
     void unionset(int x , int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx==rooty)return ;
        if(size[rootx]>size[y]){
            parent[rooty] = rootx;
            size[rootx]+=rooty;
        }else{
            parent[rootx] = rooty;
            size[rooty]+=rootx;
        }
     }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       int n = accounts.size();
       disjoinset(n);
       unordered_map<string , int>emailparent;
       for(int i=0;i<n;i++){
        for(int j = 1;j<accounts[i].size();j++){
           if(emailparent.find(accounts[i][j])!=emailparent.end()){
            unionset(i , emailparent[accounts[i][j]]);
           }else{
            emailparent[accounts[i][j]] = i;
           }
        }
       }

       vector<vector<string>>merge(n);
       for(auto& it : emailparent){
        int node = find(it.second);
        merge[node].push_back(it.first);
       }
       vector<vector<string>>ans;
       for(int i=0;i<n;i++){
        if(merge[i].empty())continue;
        sort(merge[i].begin() , merge[i].end());
        merge[i].insert(merge[i].begin() ,accounts[i][0] );
        ans.push_back(merge[i]);
       }
        return ans;
    }
};