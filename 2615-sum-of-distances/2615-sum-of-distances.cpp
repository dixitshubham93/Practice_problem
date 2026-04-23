class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int , pair<long long,long long>>mp;
        int n = nums.size();
        vector<long long>ans(n);
        for(int i = 0;i<n;i++){
            if(mp.count(nums[i])!=0){
            ans[i] = abs((long long)i*mp[nums[i]].second - (long long)mp[nums[i]].first);
            }
            mp[nums[i]].first+=i;
            mp[nums[i]].second++;
        }
        unordered_map<int , pair<long long,long long>>mp2;
        for(int i = n-1;i>=0;i--){
           if(mp2.count(nums[i])!=0){
           ans[i] += abs((long long)i*mp2[nums[i]].second - (long long)mp2[nums[i]].first);
           }
           mp2[nums[i]].first+=i;
           mp2[nums[i]].second++;
        }
        return ans;
    }
};