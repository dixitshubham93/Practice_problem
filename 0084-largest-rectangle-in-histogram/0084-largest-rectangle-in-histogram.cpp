class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int maxArea = 0;
        int n = h.size();

        for(int i = 0; i <= n; i++) {
            int curr = (i == n ? 0 : h[i]);

            while(!st.empty() && h[st.top()] > curr) {
                int height = h[st.top()];
                st.pop();

                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};
