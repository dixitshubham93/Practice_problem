class Solution {
public:
   bool allstar(string t,int n)
   {
    while(n>-1)
    {
        if(t[n]!='*'){return false;}
        n--;
    }
    return true;
   }

    int solve(string &s, string &t, int i, int j, vector<vector<int>>& dp) {   
        if(i<0&&j<0){return 1;}  
        else if(j<0){return 0;}
        else if(i<0){return allstar(t,j);}
        
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]||t[j]=='?') {
            return dp[i][j] = solve(s, t, i - 1, j - 1, dp);  // FIXED
        }else if(t[j]!='*')
        {return dp[i][j]=false;}

        int stand =  solve(s, t, i, j - 1, dp);     // insert
        int skip = solve(s, t, i - 1, j, dp);     // delete
        
        return dp[i][j] = skip||stand;
    }

    

    bool isMatch(string s, string t) {
         int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return  solve(s, t, n - 1, m - 1, dp);
    }
};