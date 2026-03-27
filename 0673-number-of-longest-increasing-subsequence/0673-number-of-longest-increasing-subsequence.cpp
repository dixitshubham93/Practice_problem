class Solution {
public:
    int findNumberOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<int>dp(n , 1);
        int mx = 1;
        vector<int>cnt(n,1);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j]){
                  if(dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    cnt[i] = cnt[j];
                  }else if(dp[i]==dp[j]+1)
                  {
                    cnt[i] +=cnt[j];
                  }                  
                }      
                mx = max(mx , dp[i]);  
            }
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            if(mx==dp[i]){count+=cnt[i];}
        }
        return count;
    }
};