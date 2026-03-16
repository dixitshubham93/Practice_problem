class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> pd(n, vector<int>(m));
        vector<vector<int>> pu(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                pd[i][j] = grid[i][j] + (i>0 && j>0 ? pd[i-1][j-1] : 0);
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < m; j++){
                pu[i][j] = grid[i][j] + (i+1<n && j>0 ? pu[i+1][j-1] : 0);
            }
        }

        set<int> st;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                st.insert(grid[i][j]); 

                int u = 1;

                while(i-u>=0 && i+u<n && j-u>=0 && j+u<m){

                    int top_i = i-u, top_j = j;
                    int right_i = i, right_j = j+u;
                    int bottom_i = i+u, bottom_j = j;
                    int left_i = i, left_j = j-u;

                    int edge1 = pd[right_i][right_j] - (top_i>0 && top_j>0 ? pd[top_i-1][top_j-1] : 0);
                    int edge2 = pu[right_i][right_j] - (bottom_i+1<n && bottom_j>0 ? pu[bottom_i+1][bottom_j-1] : 0);
                    int edge3 = pd[bottom_i][bottom_j] - (left_i>0 && left_j>0 ? pd[left_i-1][left_j-1] : 0);
                    int edge4 = pu[top_i][top_j] - (left_i+1<n && left_j>0 ? pu[left_i+1][left_j-1] : 0);

                    int area = edge1 + edge2 + edge3 + edge4
                               - grid[top_i][top_j]
                               - grid[right_i][right_j]
                               - grid[bottom_i][bottom_j]
                               - grid[left_i][left_j];

                    st.insert(area);
                    u++;
                }
            }
        }

        vector<int> ans;
        for(auto it = st.rbegin(); it != st.rend() && ans.size() < 3; ++it){
            ans.push_back(*it);
        }

        return ans;
    }
};