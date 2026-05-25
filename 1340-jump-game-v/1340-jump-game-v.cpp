class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
       int maxAns = 0;
       int n = arr.size();
       vector<int>dp(n , -1);

       for(int i = 0;i < n;i++){
          maxAns = max(maxAns , solve(arr , i , d , dp));
       }
        for(int i = 0;i < n;i++){
          cout<<dp[i]<<" ";
       }
       return maxAns;
    }

    int solve(vector<int>&arr , int i , int d , vector<int>&dp){

        if(i<0||i>=arr.size()){return 0;}
        int n = arr.size();
        // left 
        if(dp[i]!=-1)return dp[i];
        int mx = 1;
        for(int j = i-1;j>=max(0 , i-d);j--){
            if(arr[j]>=arr[i])break;
            mx = max(mx , 1 + solve(arr , j , d , dp));
        }
        // right
         for(int j = i+1;j <= min(i+d , n-1);j++){
            if(arr[i]<=arr[j])break;
            mx = max(mx , 1 + solve(arr , j , d , dp));
        }
       return dp[i] = mx;
    }

};