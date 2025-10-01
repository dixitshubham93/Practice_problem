class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n , vector<int>(n , INT_MAX));
       for(int i=0;i<n;i++){matrix[i][i] = 0;}
       for(auto& edge  : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        matrix[u][v] = w;
         matrix[v][u] = w;
       }
        for(int via = 0 ;via<n;via++){
           for(int i = 0;i<n;i++){
               for(int j =0;j<n;j++){
                   if(matrix[i][via]!=INT_MAX&&matrix[via][j]!=INT_MAX){
                      matrix[i][j]  = min(matrix[i][j] ,matrix[i][via]+matrix[via][j]);
                   }
                   
               }
           }
       }
        int ans = -1;
        int no_city = INT_MAX;
        for(int i = 0;i<n;i++){
              int count =0;
               for(int j =0;j<n;j++){
                   if(matrix[i][j]<=distanceThreshold){
                      count++;
                   }  
               }
               if(no_city>=count){
                ans = i;
                no_city = count;
               }
           }
           return ans;
    }
};