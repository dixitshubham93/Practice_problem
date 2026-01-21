class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        stack<int>st;

        int water = 0;
        for(int i = 0;i<n;i++){

            if(st.empty()){
            st.push(i);
            continue;
            }

            while(!st.empty()&&height[st.top()]<height[i]){
                int tp = st.top();
                st.pop();
                 int width = 0;
                if(!st.empty()){
                 width = i - st.top()-1;
                }
                int ht;
                if(st.empty()){
                   ht  = 0;
                }else{
                  ht = min(height[st.top()] , height[i]) - height[tp];
                }

                water += ht*width ;
            }
           st.push(i);
        }
        return water;
    }
};