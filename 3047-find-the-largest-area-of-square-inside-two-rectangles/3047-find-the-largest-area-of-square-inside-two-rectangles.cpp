class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int MaxSide = 0;
        for(int i = 0 ; i<n-1; i++){
            for(int j = i+1;j<n;j++){

               int topX = min(topRight[i][0],topRight[j][0]);
               int topY = min(topRight[i][1],topRight[j][1]);
               
               int BottomX = max(bottomLeft[i][0],bottomLeft[j][0]);
               int BottomY = max(bottomLeft[i][1],bottomLeft[j][1]);
               
               int width = topX - BottomX;
               int height = topY - BottomY;
               
               MaxSide =max(MaxSide , min(width , height)); 
            }
        }
        return 1ll*MaxSide*MaxSide;
    }
};