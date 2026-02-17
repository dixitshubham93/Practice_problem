class Solution {
public:
    int atmost(vector<int>& nums, int goal){
        int left = 0;
        int sum  =0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i]%2;
            while(sum>goal&&left<=i){
                sum -= nums[left]%2;
                left++;
            }
            ans += i - left +1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums , k) - atmost(nums , k - 1);
    }
};