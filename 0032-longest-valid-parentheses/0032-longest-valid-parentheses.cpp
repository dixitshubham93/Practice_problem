class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Base index
        int max_len = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // New boundary
                } else {
                    max_len = max(max_len, i - st.top());
                }
            }
        }
        return max_len;
    }
};