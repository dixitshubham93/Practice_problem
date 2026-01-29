class Solution {
public:
    void getFloyd(vector<vector<int>>& floyd) {
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (floyd[i][k] == INT_MAX || floyd[k][j] == INT_MAX)
                        continue;
                    floyd[i][j] = min(floyd[i][j],
                                      floyd[i][k] + floyd[k][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        vector<vector<int>> floyd(26, vector<int>(26, INT_MAX));

     
        for (int i = 0; i < 26; i++) {
            floyd[i][i] = 0;
        }

        
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            floyd[u][v] = min(floyd[u][v], cost[i]);
        }

        getFloyd(floyd);

        long long minCost = 0;

        for (int i = 0; i < source.size(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if (floyd[u][v] == INT_MAX)
                return -1;

            minCost += floyd[u][v];
        }

        return minCost;
    }
};
