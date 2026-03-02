class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int mxarea = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                mxarea = max(mxarea, h * width);
            }

            st.push(i);
        }

        while(!st.empty()) {
            int h = heights[st.top()];
            st.pop();

            int width = st.empty() ? n : n - st.top() - 1;
            mxarea = max(mxarea, h * width);
        }

        return mxarea;
    }
};