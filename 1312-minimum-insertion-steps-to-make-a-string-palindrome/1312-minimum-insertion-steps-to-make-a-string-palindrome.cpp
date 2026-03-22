class Solution {
public:
    int dp[502][502];
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
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};