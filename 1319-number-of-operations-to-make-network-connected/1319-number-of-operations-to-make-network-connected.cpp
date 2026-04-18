class Solution {
public:
    vector<int>parent;
    vector<int>size;
    void DSU(int n){
        size.assign(n , 1);
        parent.assign(n , 1);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int x){
     if(parent[x] == x)return x;
     return parent[x] = find(parent[x]);
    }
    void Union(int x , int y){
        int rootx = find(x);
        int rooty = find(y);

        if(rootx==rooty){return;}
        if(size[rootx]>=size[rooty]){
            parent[rooty] = rootx;
            size[rootx] += size[rooty];
        }else{
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){return -1;}
        DSU(n);
        for(auto& it : connections){
            int u = it[0];
            int v = it[1];
            if(find(u)!=find(v)){
                Union(u , v);
            }
        }
        int ans = -1;
        for(int i = 0;i<n;i++){
            if(parent[i] == i){
             ans++;
          }
        }
        return ans;
    }
};