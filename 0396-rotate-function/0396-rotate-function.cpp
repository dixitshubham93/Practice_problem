class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = accumulate(nums.begin() , nums.end() , 0LL);
        long long temp = 0;
        long long ans = INT_MAX;
        int n = nums.size();

        for(int i = 0;i<nums.size();i++){
           temp += nums[i]*i;
        }
        ans = temp;
        for(int i  =0;i<nums.size();i++){
          temp -= (sum-nums[i]);
          temp += (n-1)*nums[i];
          ans = max(ans ,temp);
        }
        return (int)ans;
    }
};