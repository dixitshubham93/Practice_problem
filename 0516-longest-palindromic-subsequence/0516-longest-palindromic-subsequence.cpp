class Solution {
public:
    int dp[1002][1002];
    // int solve(string s , int start , int end){
    // if(start>end){return 0;}
   
    // if(start==end){return s[start]==s[end];}
    // if(dp[start][end]!=-1){return dp[start][end];}
    // if(s[start]==s[end]){
    //     return 2 + solve(s , start+1 , end-1);
    // }
    //  int l = solve(s , start+1 , end);
    //  int r = solve(s , start , end-1);
    //  return dp[start][end] = max(l  ,r);
    // }
    int lcs(string s, string t){
        memset(dp , 0 , sizeof(dp));
        int n = s.size();

        for(int start = 1;start<=n;start++){
           for(int end = 1;end<=n;end++){
             if(s[start-1]==t[end-1]){
                dp[start][end] = 1+dp[start-1][end-1];
                continue;
             }
             dp[start][end] = max(dp[start][end-1] ,dp[start-1][end]);
           }
        }
         
        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
       string t = s;
       reverse(s.begin() , s.end());
       return lcs(s , t);
    }
};