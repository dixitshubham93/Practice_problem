class Solution {
public:
    int atmost(vector<int>& nums, int goal){
        int left = 0;
        int sum  =0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            while(sum>goal&&left<=i){
                sum -= nums[left];
                left++;
            }
            ans += i - left +1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      return atmost(nums , goal ) - atmost(nums , goal - 1);
    }
};