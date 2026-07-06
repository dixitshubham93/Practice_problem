class DSU{
    public:
     vector<int>parent;
     vector<int>size;

     DSU(int n ){
        size.resize(n+1 ,1);
        parent.resize(n+1 ,0);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
     }
     int find(int x){
        if(parent[x]==x)return x;
        return parent[x] = find(parent[x]);
     }
     void Union(int a  , int b){
        int root_a = find(a);
        int root_b = find(b);
        if(root_a==root_b)return ;
        if(size[root_a]>=size[root_b]){
            parent[root_b] = root_a;
            size[root_a]+=size[root_b];
        }else{
            parent[root_a] = root_b;
            size[root_b]+=size[root_a];
        }
     }
};
class Solution {
public:
    
    int minScore(int n, vector<vector<int>>& roads) {
        if(n==1)return 0;
        DSU* dsu = new DSU(n+1);
        int ans = INT_MAX;
        for(auto&it : roads){
           int u = it[0];
           int v = it[1];
           dsu->Union(u , v);
        }
        int root = dsu->find(1);
        for(auto&it : roads){
         if(dsu->find(it[0])==root){
         ans = min(ans , it[2]);
         }
        }
        return ans;
    }
};