class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int  n= heights.size();
        int  m = heights[0].size();
         
        priority_queue<vector<int>,vector<vector<int>> ,greater<vector<int>>>q;

        q.push({0 ,0, 0});

        int rv[4] = {-1,0,1,0};
        int cv[4] = {0,-1,0,1};

        vector<vector<int>>efforts(n , vector<int>(m,INT_MAX));

        efforts[0][0] = 0;

        while(!q.empty()){
           auto vec = q.top();
           int raw = vec[1];
           int col = vec[2];
           int eff  = vec[0];
           q.pop();
           for(int i=0;i<4;i++){

            int ri = raw + rv[i];
            int ci = col + cv[i];

            if(ri>=0&&ri<n&&ci>=0&&ci<m&&max(eff , abs(heights[raw][col]-heights[ri][ci]))<efforts[ri][ci]){
                efforts[ri][ci] = max(eff , abs(heights[raw][col]-heights[ri][ci]));
                q.push({efforts[ri][ci] , ri , ci});
            }
           }
        }

        return efforts[n-1][m-1];
    }
};