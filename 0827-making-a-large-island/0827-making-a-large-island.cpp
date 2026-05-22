class Solution {
public:

    vector<int>parent;
    vector<int>size;

    void DSU(int n){
        size.assign(n , 1);
        parent.assign(n , 1);
        for(int i = 0;i<n;i++){parent[i] = i;}
    }
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x] = find(parent[x]);
    }
    bool Union(int x , int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx==rooty)return false;
        if(size[rootx]>=size[rooty]){
            parent[rooty] = rootx;
            size[rootx] += size[rooty];
        }else{
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
      return true;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU(n*n + 5);

        int dr[4] = {0 , 0 , -1 , 1};
        int dc[4] = {1 , -1 , 0 , 0 };
  
        for(int i = 0;i<n;i++){
           for(int j = 0;j<n;j++){
            if(grid[i][j] == 0)continue;
              int node = i*n + j;
              for(int k = 0;k<4;k++){
                int newr = i+ dr[k];
                int newc = j+ dc[k];
                int newn = newr*n + newc;
                if(newr<0||newr>=n||newc<0||newc>=n){continue;}
                 if(grid[newr][newc]==1){
                    Union(node , newn);
                 }
              }
           }
        }
        int maxsize = 0;
        for(int i= 0;i<n*n+5;i++){maxsize = max(size[i] , maxsize);}

        for(int i = 0;i<n;i++){
           for(int j = 0;j<n;j++){
           if(grid[i][j] == 1)continue;
              int node = i*n + j;
              int temp = 1;
              set<int>st;
              for(int k = 0;k<4;k++){
                int newr = i+ dr[k];
                int newc = j+ dc[k];
                
                int newn = newr*n + newc;
                if(newr<0||newr>=n||newc<0||newc>=n){continue;}   
                if(grid[newr][newc]!=1){continue;}
                st.insert(find(newn));      
              }
              for(int it : st){
                temp += size[it];
              }
              maxsize = max(temp , maxsize);
           }
        }
        return maxsize;
    }
};