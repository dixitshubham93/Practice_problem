class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        queue<pair<int , int>>q;
        q.push({sr , sc});
        int start = image[sr][sc];
        if(start==color){return image;}
        int n = image.size();
        int m = image[0].size();
        image[sr][sc] = color;
        int dr[4] = {0 , 0 , -1 , 1};
        int dc[4] = {1 , -1 , 0 , 0};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(int i  = 0;i<4;i++){
                int row = it.first + dr[i];
                int col = it.second + dc[i];
                if(row<0||row>=n||col<0||col>=m){continue;}

                if(image[row][col]==start){
                    image[row][col] = color;
                    q.push({row , col});
                }
            }
        }
        return image;
    }  
};