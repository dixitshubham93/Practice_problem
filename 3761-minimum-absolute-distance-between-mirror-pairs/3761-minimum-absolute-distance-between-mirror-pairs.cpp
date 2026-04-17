class Solution {
public:
    int reverse(int x){
        int num = 0;
        while(x){
            num = num*10+x%10;
            x = x/10;
        }
      return num;
    }
 
    int minMirrorPairDistance(vector<int>& nums){
        unordered_map<int , int>mp;
        int ans = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            if(mp.count(nums[i])){
              ans = min(ans , i - mp[nums[i]]);
            }

            mp[reverse(nums[i])] = i;
        }
        return ans==INT_MAX?-1:ans;
    }
};