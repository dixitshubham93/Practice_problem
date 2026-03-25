class Solution {
public:
int dp[1001][101][3];
    int solve(vector<int>& prices , int idx , int k , int isSell){
      if(idx>=prices.size()){return 0;}
      if(k==0){return 0;}
      if(dp[idx][k][isSell]!=-1){return dp[idx][k][isSell];}
      if(isSell){
        return dp[idx][k][isSell]= max(prices[idx]+solve(prices , idx+1 , k-1 , !isSell),solve(prices , idx+1 , k, isSell));
      }
      return dp[idx][k][isSell] =max(-prices[idx]+solve(prices , idx+1 , k , !isSell),solve(prices , idx+1 , k, isSell));
    }
    int maxProfit(int k, vector<int>& prices) {
         memset(dp , -1 , sizeof(dp));
     return solve(prices , 0 , k , 0);
    }
};