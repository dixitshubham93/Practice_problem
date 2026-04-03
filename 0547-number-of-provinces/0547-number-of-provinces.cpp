class Solution {
public:
   vector<int>size;
   vector<int>parent;
   void DSU(int n){
    size.assign(n , 1);
    parent.assign(n , 0);
    for(int i = 0;i<n;i++){parent[i] = i;}
   }
   int find(int x){
     if(x==parent[x])return x;
     return parent[x] = find(parent[x]);
   }
   void add(int x  , int y){
    int root_x = find(x);
    int root_y = find(y);

    if(root_x==root_y){return ;}

    if(size[root_x]>size[root_y]){
       size[root_x] += size[root_y];
       parent[root_y] = root_x;
    }else{
       size[root_y] += size[root_x];
       parent[root_x] = root_y;
    }
   }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU(n);
        for(int i = 0 ;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]){
                    add(i , j);
                }
            }
        }
        
        int count = 0;
        for(int i= 0;i<n;i++){
            if(i == parent[i]){
                count++;
            }
        }
      return count;
    }
};