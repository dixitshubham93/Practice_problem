class Solution {
public:
    vector<int>parent;
    vector<int>size;
   void DisjointSet(int V){
       size.resize(V,1);
       parent.resize(V,0);
       for(int i=0;i<V;i++){
           parent[i] = i;
       }
       return ;
   }
   
   int find(int X){
       if(X == parent[X])return X;
       return parent[X] = find(parent[X]);
   }
  void Union(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx == rooty) return;

    if (size[rootx] > size[rooty]) {
        parent[rooty] = rootx;
        size[rootx] += size[rooty];
    } else {
        parent[rootx] = rooty;
        size[rooty] += size[rootx];
    }
}
   
    int makeConnected(int n, vector<vector<int>>& edges) {
         int e = edges.size();
        DisjointSet(n);
        
        for(auto & edge : edges){
            int x = edge[0];
            int y = edge[1];
            Union(x , y);
        }
        
        if(e<n-1){
            return -1;
        }
        int noOfprovience = 0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                noOfprovience++;
            }
        }
        return noOfprovience-1;
    }
};