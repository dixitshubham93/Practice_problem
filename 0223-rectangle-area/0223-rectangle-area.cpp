class Solution {
public:
   
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        
               int topX = min(ax2,bx2);
               int topY = min(ay2 , by2);
               
               int BottomX = max(ax1,bx1);
               int BottomY = max(ay1,by1);

            
               int width = topX - BottomX;
               int height = topY - BottomY;
               int IntersectionArea = width*height;
               
               int FirstArea = (ax2 - ax1)*(ay2-ay1);
               int SecondArea = (bx2 - bx1)*(by2-by1);
               int TotalArea = FirstArea + SecondArea;
               if(width<0||height<0){return TotalArea;}
          
        return TotalArea -  IntersectionArea;
    }
};