class Solution {
public:
    typedef long long ll;
    ll dp[101][201][2];
    ll solve(int first , int M , int turn , vector<int>&prefix){
        if(first>=prefix.size()){
            return 0;
        }
      if(dp[first][M][turn]!=-1)return dp[first][M][turn];
      int n = prefix.size();
      ll ans = turn==0?INT_MIN:INT_MAX;
      if(turn == 0){
        for(int i = 1;i<=2*M;i++){
          if((n-first)<i){break;}
          ans = max(ans ,(prefix[first+i-1]-(first==0?0:prefix[first-1]))+solve(first+i , max(M , i),1 , prefix));
        }
      }else{
        for(int i = 1;i<=2*M;i++){
          if((n-first)<i){break;}
          ans = min(ans ,-1*(prefix[first+i-1]-(first==0?0:prefix[first-1]))+solve(first+i , max(M , i),0 , prefix));
        }
      }
      return dp[first][M][turn] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int>prefix(n);
        prefix[0] = piles[0];
        memset(dp , -1 , sizeof(dp));
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1]+ piles[i];
        }
       ll diff = solve(0 , 1 , 0 , prefix);
       cout<<diff<<endl;
       ll sum = prefix[n-1];
       ll score = diff + (sum-diff)/2;
       return score;
    }
};