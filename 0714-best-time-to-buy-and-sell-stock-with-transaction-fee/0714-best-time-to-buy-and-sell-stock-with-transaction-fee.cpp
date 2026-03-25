class Solution {
public:
int dp[50000][3];
    int solve(vector<int>& prices , int idx , int isSell , int fee){
      if(idx>=prices.size()){return 0;}
      if(dp[idx][isSell]!=-1){return dp[idx][isSell];}
      if(isSell){
        return dp[idx][isSell]= max(-fee+prices[idx]+solve(prices , idx+1  , !isSell , fee),solve(prices , idx+1 , isSell,fee));
      }
      return dp[idx][isSell] =max(-prices[idx]+solve(prices , idx+1 , !isSell,fee),solve(prices , idx+1 , isSell,fee));
    }
    int maxProfit(vector<int>& prices , int fee){
         memset(dp , -1 , sizeof(dp));
     return solve(prices , 0 , 0 , fee);
    }
};