class Solution {
public:

   map<pair<int , int>,pair<int , int>>parent;
   map<pair<int , int>,int>size;

 
   
   pair<int , int> find(pair<int , int>x){
       if(x == parent[x])return x;
       return parent[x] = find(parent[x]);
   }
  void Union(pair<int , int> x, pair<int ,int> y) {
    pair<int , int> rootx = find(x);
    pair<int  ,int> rooty = find(y);
    if (rootx == rooty) return;

    if (size[rootx] > size[rooty]) {
        parent[rooty] = rootx;
        size[rootx] += size[rooty];
    } else {
        parent[rootx] = rooty;
        size[rooty] += size[rootx];
    }
}
   
    int Solve(int n, vector<vector<int>>& edges) {
        
         for(auto & edge : edges){
            parent[{edge[0] , edge[1]}] = {edge[0],edge[1]};
        }
        for(auto & edge : edges){
            size[{edge[0] , edge[1]}] = 1;
        }

        for(int i=0;i<n-1;i++){
            for(int j =i+1;j<n;j++){
                pair<int , int> pair1 = {edges[i][0],edges[i][1]};
                pair<int , int> pair2 = {edges[j][0],edges[j][1]};
                if(pair1.first==pair2.first||pair1.second==pair2.second){
                    Union(pair1, pair2);
                }
            }
        }
        
        
        int ans = 0;
        for (auto& it : parent) {
    if (it.first == it.second) {  
        ans += size[{it.first.first,it.first.second}] - 1;
    }
}
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        return Solve( n , stones);
    }
};