class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {

      int n = heightMap.size();
      int m = heightMap[0].size();
      vector<vector<bool>>visited(n , vector<bool>(m ,false ));

      priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int , int>>> , greater<>>boundries;

      for(int i=0;i<m;i++){
        boundries.push({heightMap[0][i] , {0 , i}});
        boundries.push({heightMap[n-1][i] , {n-1 , i}});
        visited[0][i] = true;
        visited[n-1][i] = true;
      }

      for(int i=0;i<n;i++){
        boundries.push({heightMap[i][0] , {i, 0}});
        boundries.push({heightMap[i][m-1] , {i , m-1}});
        visited[i][0] = true;
        visited[i][m-1] = true;
      }
       int totalwater = 0;
       int dir[4] = {-1,1,0,0};
       int dic[4] = {0,0,-1,1};
       while(!boundries.empty()){
        int height = boundries.top().first;
        int row    = boundries.top().second.first;
        int col    = boundries.top().second.second;
        boundries.pop();
        for(int i=0;i<4;i++){
            int rw = row + dir[i];
            int cl = col + dic[i];
            if(rw>=0&&rw<n&&cl>=0&&cl<m&&!visited[rw][cl]){
               if(height>heightMap[rw][cl]){
                totalwater += height-heightMap[rw][cl];
                visited[rw][cl] = true;
                boundries.push({height , {rw , cl}});
               }else{
                visited[rw][cl] = true;
                boundries.push({heightMap[rw][cl] , {rw , cl}});
               }
            }
        }

       }
      return totalwater;
    }
};