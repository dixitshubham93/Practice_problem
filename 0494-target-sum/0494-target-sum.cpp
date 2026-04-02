class Solution {
public:
    unordered_map<int , unordered_map<int , int>>mp;
    int solve(vector<int>& nums , int idx , int target){
        if(idx>=nums.size()){
            return target==0;
        }
        if(mp.count(idx)&&mp[idx].count(target)){return mp[idx][target];}
        int l = solve(nums , idx+1 , target+nums[idx]);
        int r = solve(nums , idx+1 , target-nums[idx]);
        return mp[idx][target] = l+r;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums , 0 , target);
    }
};