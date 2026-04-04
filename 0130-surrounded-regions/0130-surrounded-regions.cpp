class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = '?';
                }
            }
        }
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            if (board[0][i] == '?') {
                board[0][i] = 'O';
                q.push({0, i});
            }
            if (board[n - 1][i] == '?') {
                board[n - 1][i] = 'O';
                q.push({n - 1, i});
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[i][0] == '?') {
                board[i][0] = 'O';
                q.push({i, 0});
            }
            if (board[i][m - 1] == '?') {
                board[i][m - 1] = 'O';
                q.push({i, m - 1});
            }
        }
        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int row = dr[i] + it.first;
                int col = dc[i] + it.second;
                if (row < 0 || row >= n || col < 0 || col >= m) {
                    continue;
                }
                if (board[row][col] == '?') {
                    board[row][col] = 'O';
                    q.push({row, col});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '?') {
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};