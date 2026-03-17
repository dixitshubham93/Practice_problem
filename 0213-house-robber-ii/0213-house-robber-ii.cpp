class Solution {
public:
    vector<int>dp;
    int solve(int idx, int e , vector<int>&nums){
        if(idx>=e){return  0;}
        if(dp[idx]!=-1)return dp[idx];
        int take = nums[idx] + solve(idx+2 , e, nums);
        int nottake =  solve(idx+1 , e , nums);
        return dp[idx]=max(nottake , take);
    }
    int rob(vector<int>& nums){
        if(nums.size()==1)return nums[0];
        int n = nums.size();
        dp.assign(n , -1);
        int l =  solve(1,n,nums) ;
        dp.assign(n , -1);
        int r = solve(0,n-1,nums);
        return max(l ,r);
    }
};