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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        disjoinset(n*n);
        priority_queue<pair<int , pair<int , int>>,vector<pair<int , pair<int , int>>> , greater<>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                q.push({grid[i][j],{i,j}});
            }
        }
        int dir[4] = {-1,1,0,0};
        int dic[4] = {0,0,-1,1};

        while(!q.empty()){
              int level = q.top().first;
              int row = q.top().second.first;
              int col= q.top().second.second;
              int pid = row*n + col;
              q.pop();
              for(int i =0;i<4;i++){
                int newrow = row + dir[i];
                int newcol = col + dic[i];
                int adjid = newrow*n + newcol;
                if(newrow>=0&&newrow<n&&newcol>=0&&newcol<n&&level>=grid[newrow][newcol]){
                      unionset(find(pid) , find(adjid));
                }
              }
              if(find(0)==find(n*n-1)){return level;}
        }
        return 0;
    }
};