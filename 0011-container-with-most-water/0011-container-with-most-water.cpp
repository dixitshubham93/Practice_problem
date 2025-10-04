class Solution {
public:
    
    int maxArea(vector<int>& height) {
       int mn = 0;
       int s = 0;
       int e = height.size()-1;
       while(s<e){
        int high = min(height[s] ,height[e]);
        int width = e-s;
        mn = max(mn , high*width);
        if(height[s]>height[e]){
            e--;
        }
        else{
            s++;
        }
       }
       return mn;
    }
};