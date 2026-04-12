class Solution {
public:

   int dp[302][27][27];
   int solve(string& word, int idx,  int x1, int x2){
    if (idx >= word.size()) return 0;
    if(dp[idx][x1+1][x2+1]!=-1){return dp[idx][x1+1][x2+1];}
    int targetX =  (word[idx]-'A')/6 ;
    int targetY  =  (word[idx]-'A')%6;

    pair<int , int>p1 = {x1/6 , x1%6};
    pair<int , int>p2 = {x2/6 , x2%6};
    int dist1 = (x1 == -1) ? 0 : abs(targetX - p1.first) + abs(targetY - p1.second);
    int moveFinger1 = dist1 + solve(word, idx + 1,(word[idx]-'A'), x2);

  
    int dist2 = (x2 == -1) ? 0 : abs(targetX - p2.first) + abs(targetY - p2.second);
    int moveFinger2 = dist2 + solve(word, idx + 1, x1, (word[idx]-'A'));

    return dp[idx][x1+1][x2+1]=min(moveFinger1, moveFinger2);
   }
    int minimumDistance(string word) {
      memset(dp , -1 , sizeof(dp));
      return solve(word , 0 , -1 , -1);
    }
};