class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums){
      unordered_map<long long , long long>mp;
      mp[0] = 1;
      int n = nums.size();
      long long ans = 0;
      int sum = 0;
      for(int i = 0;i<n;i++){
        sum = sum^nums[i];
        if(mp.count(sum)>0){
            ans += 1LL*mp[sum];
        }
        mp[sum]++;
      }
      return ans;
    }
};