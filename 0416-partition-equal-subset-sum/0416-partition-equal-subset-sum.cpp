class Solution{
public:

    vector<vector<int>>dp;
    int solve(int temp , int idx , vector<int>&nums){
      if(idx>=nums.size()){return temp==0?1:0;}
      if(temp==0){return 1;}
      if(temp<0){return 0 ;}

      if(dp[idx][temp]!=-1){return dp[idx][temp];}

      int l = solve(temp , idx+1 , nums);
      int r = solve(temp-nums[idx] , idx+1 , nums);
      return dp[idx][temp] = l||r;
    }
    bool canPartition(vector<int>& nums){
        int sum = accumulate(nums.begin() , nums.end() , 0);
        cout<<sum<<endl;
        if(sum%2!=0){return false;}
        int n = nums.size();
        int temp = sum/2;
        dp.assign(n+1,vector<int>(temp+1, -1));
        return solve(temp , 0 , nums)==0?false:true;
    }
};