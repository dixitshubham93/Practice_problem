class Solution {
public:
    vector<int>dp;
    int solver(int n){
     if(n<=1)return 1;
     if(dp[n]!=-1)return dp[n];
        return dp[n] = solver(n-1)+solver(n-2);
    }
    int climbStairs(int n) {
    dp.assign(n+1 , -1);
    return  solver(n);
    }
};