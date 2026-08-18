class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int ,int>mp;
        for(int i = 0;i<n;i++)mp[nums[i]]++;
        int ans = -1;

        if(k==1||k==n){
            for(auto it: mp){
                if(it.second==1||k==n){
                    ans = max(ans , it.first);
                }
            }
            return ans;
        }else{
           if(mp[nums[0]]==1&&mp[nums[n-1]]==1){
            return max(nums[0],nums[n-1]);
           }else if(mp[nums[0]]==1||mp[nums[n-1]]==1){
            return mp[nums[0]]==1?nums[0]:nums[n-1];
           }
        }
        return -1;
    }
};