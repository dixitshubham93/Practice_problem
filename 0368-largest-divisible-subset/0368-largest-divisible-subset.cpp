class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums){
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<int>dp(n , 1);
        vector<int>parent(n , -1);
        int mx = 1;
        int ind = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i]%nums[j]==0){
                   if(dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                   }
                   if(dp[i]>mx){
                    mx = dp[i];
                    ind = i;
                   }                  
                }
            }
        }
        vector<int>ans;
        while(ind!=-1){
           ans.push_back(nums[ind]);
           ind = parent[ind];
        }

      return ans;
    }
};