class Solution {
public:

    vector<int> parent, size;

    void DisjointSet(int V) {
        parent.resize(V);
        size.resize(V, 1);
        for (int i = 0; i < V; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
            return false;

        if (size[rootx] > size[rooty]) {
            parent[rooty] = rootx;
            size[rootx] += size[rooty];
        } else {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
        return true; 
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet(n*n);
        int row[4] = {1, 0, -1, 0};
        int col[4] = {0, -1, 0, 1};
        int count = 0;
              
        for (int i = 0; i < n; i++){
           for(int j =0;j<n;j++){
            int nodeid = i*n+j;
            for (int k = 0; k < 4; k++) {
                int nr = i + row[k], nc = j + col[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    grid[i][j] == 1 && grid[nr][nc] == 1) {
                    int adjId = nr*n + nc;
                    Union(nodeid, adjId)  ;
                    }
                }
            } 
          }
          int ans = 0;
          for(int i=0;i<n*n;i++){
                ans = max(ans , size[i]);
          }
          for (int i = 0; i < n; i++){
           for(int j =0;j<n;j++){
            int nodeid = i*n+j;
             
              set<int>tem_parent;
            for (int k = 0; k < 4; k++) {
                int nr = i + row[k], nc = j + col[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    grid[nr][nc] == 1&&grid[i][j] == 0) {
                    int adjId = nr*n + nc;
                      tem_parent.insert(find(adjId))  ;
                    }
                }
                 int temp =1;
                 for(int it : tem_parent){
                    temp+=size[it];
                 }
                 ans=max(ans , temp);
            } 
          }
        

        return ans;
    }
};