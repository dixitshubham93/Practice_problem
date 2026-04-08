class Solution {
public:

    long long  MOD = 1e9 + 7;
    void solve(vector<int>&nums , int l , int r , int k , int v){
      for(int i = l;i<=r;i+=k){
        nums[i] = ((long long)nums[i]%MOD * v%MOD) % (MOD);
      }
      return ;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long ans = 0;
        
       for(auto& it : queries){
         solve(nums , it[0] ,it[1] ,it[2] ,it[3]);
       }
       for(int i = 0;i<nums.size();i++){
        ans = ans^nums[i];
       }
       return ans;
    }
};