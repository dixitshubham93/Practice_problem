class Solution {
public:
    unordered_map<int , int>parent;
    unordered_map<int , int>size;
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
    int removeStones(vector<vector<int>>& stones){
       for(auto& it : stones){
          int row  = it[0];
          int col  = it[1] + 1e4+1;
          if(!parent.count(row)){parent[row] = row;}
          if(!parent.count(col)){parent[col] = col;}
          if(find(row)!=find(col)){
            Union(row , col);
          }
       }
       int temp = 0;
       for(auto&[key , value] : parent){
            if(key == value){
             temp++;
          }
        }
      return stones.size() - temp; 
    }
};