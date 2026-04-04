class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){

        queue<pair<int , int>>q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>distance( n , vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(mat[i][j]==0){
                  q.push({i , j});
                }
            }
        }

        int dis = 0;

        int dr[4] = {1 , - 1, 0 , 0};
        int dc[4] = {0 , 0 , 1 , -1};

        while(!q.empty()){
            int size = q.size();
            dis++;
            for(int i = 0;i<size;i++){
             auto it = q.front();
             q.pop();
             for(int j = 0;j<4;j++){
                int row = it.first + dr[j];
                int col = it.second + dc[j];

                if(row<0||row>=n||col<0||col>=m){continue;}

                if(mat[row][col]==1){
                   mat[row][col] = 0;
                   q.push({row , col});
                   distance[row][col] = dis;
                }
            }
          }

        }

        return distance;    
    }
};