class Solution {
public:
    int mod = 1e9+7;
    int dp[1001][1001][2];

    long long solve(int i,int total,int isStarted , int n , int k ){
        if (i == n) {
         if (isStarted)
           return 0;       
          return total == k;
        }
        if(dp[i][total][isStarted]!=-1)return dp[i][total][isStarted];
        
        long long ans = 0;
        if(!isStarted){
            ans += solve(i+1,total,1 , n , k)%mod;
            ans += solve(i+1 , total,0,n,k)%mod;
        }else{
            ans += solve(i+1 , total,isStarted,n,k)%mod;
            ans += solve(i+1 , total+1,0,n,k)%mod;
            ans += solve(i+1 , total+1,isStarted,n,k)%mod;
        }
        return dp[i][total][isStarted]=ans%mod;
    }
    int numberOfSets(int n, int k) {
        memset(dp , -1 , sizeof(dp));

        return solve(0 , 0 , 0 , n , k);
    }
};