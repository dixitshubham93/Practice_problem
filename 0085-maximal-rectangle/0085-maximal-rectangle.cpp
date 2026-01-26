class Solution {
public:
    int maxSumReactangle(vector<int>& histo) {
        int n = histo.size();
        int ans = 0;
        stack<int> st;

        for (int i = 0; i <= n; i++) {
            int curr = (i == n ? 0 : histo[i]);

            while (!st.empty() && histo[st.top()] > curr) {
                int height = histo[st.top()];
                st.pop();

                int width;
                if (st.empty()) width = i;
                else width = i - st.top() - 1;

                ans = max(ans, height * width);
            }
            st.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> histo(m, 0);
        int mx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') histo[j]++;
                else histo[j] = 0;
            }
            mx = max(mx, maxSumReactangle(histo));
        }
        return mx;
    }
};
