class Solution {
public:
    unordered_map<int , unordered_map<int , unordered_map<int , int>>>mp;

    int solve(int s , int e , vector<int>&nums , int turn){
      if(s==e){
        return turn==1?nums[s]:0;
      }
      if(mp.count(s)&&mp[s].count(e)&&mp[s][e].count(turn)){
        return mp[s][e][turn];
      }
      int ans = 0;
      if(turn==1){
       ans  = nums[s]+solve(s+1 , e , nums , 0);
       ans  = max(ans,nums[e]+solve(s , e-1 , nums , 0));
      }else{
        ans = min(solve(s+1, e, nums, 1),
              solve(s, e-1, nums, 1));
       } 
      return mp[s][e][turn]=ans;
    }
    bool predictTheWinner(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    for(int i : nums)sum+=i;
    int ans = solve(0 , n-1 , nums , 1);

    cout<<ans<<endl;

    return ans>=(sum-ans);
    }
};