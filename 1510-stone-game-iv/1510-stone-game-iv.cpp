
class Solution {
public:
    vector<int>perfactSquare;
    vector<vector<int>>dp;
    bool SquareGame(int n , int turn ){
        if(n==0)return turn==1;
        if(dp[n][turn]!=-1)return dp[n][turn]==1;
        if(turn==0){
           for(auto it : perfactSquare){
            if(it>n){break;}
            if(SquareGame(n-it , 1))return dp[n][turn]=true;
           }
        }else if(turn == 1){
            for(auto it : perfactSquare){
            if(it>n){break;}
            if (!SquareGame(n - it, 0))
              return dp[n][turn] = false;
           }
           return dp[n][turn] = true;
        }
        return dp[n][turn]=false;
    }
    bool winnerSquareGame(int n) {
        for(int i = 1;i*i<=n;i++){
          perfactSquare.push_back(i*i);
        }
        dp.assign(n+1 , vector<int>(2 , -1));

       return SquareGame(n , 0);
    }
};