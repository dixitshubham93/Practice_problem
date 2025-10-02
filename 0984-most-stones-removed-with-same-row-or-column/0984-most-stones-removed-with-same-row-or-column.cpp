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
   
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
       int maxRow = 0;
       int maxCol = 0;
       for(auto it : stones){
        maxRow = max(maxRow , it[0]);
        maxCol = max(maxCol , it[1]);
       }
       DisjointSet(maxRow + maxCol+2);
       unordered_map<int , int>nodeStone;
       for(auto it : stones){
        int nodeRow = it[0];
        int nodecol = maxRow+1+ it[1];
        Union(nodeRow , nodecol);
        nodeStone[nodeRow] = 1;
        nodeStone[nodecol] = 1;
       }

       int count =0;
       for(auto it : nodeStone){
        if(parent[it.first]==it.first){
            count++;
        }
       }
      return n-count;
    }
};