class Solution {
public:
   
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        int n = nums.size();
        mp[0] = 1;
        int ans = 0;
        vector<int>prefix(n+1);

        for(int i=0;i<n;i++){
         prefix[i+1] = prefix[i] + nums[i];
        }
        for(int i = 0;i<n;i++){
            if(mp.count(prefix[i+1]-k)>0){
                ans += mp[prefix[i+1]-k];
            }
            mp[prefix[i+1]]++;
        }
        return ans;     
    }
};