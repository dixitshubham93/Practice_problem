class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int ans = 0;
        for(int i = 0;i<height.size();i++){
            while(!st.empty()&&height[st.top()]<height[i]){
                int h = height[st.top()];
                st.pop();
                if(!st.empty()){
                    int  high = min(height[i],height[st.top()])-h;
                    int  width = i - st.top()-1;
                    ans += high*width;
                }
            }
            st.push(i);
        }
        return ans;
    }
};