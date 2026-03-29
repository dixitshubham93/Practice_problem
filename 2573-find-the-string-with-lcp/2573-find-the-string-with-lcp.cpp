class Solution {
public:
   
    string findTheString(vector<vector<int>>& lcp) {      
        int n = lcp.size();
        vector<vector<int>> mark(n);

       
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(lcp[i][j] != lcp[j][i]) return "";

                if(i == j && lcp[i][j] != n - i) return "";

                if(j < i && lcp[i][j] == 0){
                    mark[i].push_back(j);
                }
            }
        }
 
        string s(n, 'a');

        for(int i = 0; i < n; i++){ 
            bool isPossible = false;     

            for(char it = 'a'; it <= 'z'; it++){
                bool conflict = false;

              
                for(int j = 0; j < mark[i].size(); j++){
                    if(s[mark[i][j]] == it){
                        conflict = true;
                        break;
                    }
                }

                if(!conflict){
                    s[i] = it;
                    isPossible = true;
                    break;
                }
            }

            if(!isPossible) return "";
        }

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(s[i] == s[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] != lcp[i][j]) return "";
            }
        }

        return s;
    }
};