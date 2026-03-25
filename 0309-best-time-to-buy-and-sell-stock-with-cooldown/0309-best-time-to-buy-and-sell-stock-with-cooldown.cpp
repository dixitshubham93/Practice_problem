class Solution {
public:
int dp[5001][3];
    int solve(vector<int>& prices , int idx , int isSell){
      if(idx>=prices.size()){return 0;}
      if(dp[idx][isSell]!=-1){return dp[idx][isSell];}
      if(isSell){
        return dp[idx][isSell]= max(prices[idx]+solve(prices , idx+2  , !isSell),solve(prices , idx+1 , isSell));
      }
      return dp[idx][isSell] =max(-prices[idx]+solve(prices , idx+1 , !isSell),solve(prices , idx+1 , isSell));
    }
    int maxProfit(vector<int>& prices){
         memset(dp , -1 , sizeof(dp));
     return solve(prices , 0 , 0);
    }
};