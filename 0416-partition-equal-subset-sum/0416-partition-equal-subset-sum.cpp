class Solution{
public:

    vector<vector<int>>dp;
    
    bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2 != 0) return false;

    int n = nums.size();
    int half = sum / 2;

    vector<vector<int>> dp(n + 1, vector<int>(half + 1, 0));

    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    
    for (int idx = 0; idx<n; idx++) {
        for (int temp = 1; temp <= half; temp++) {

            int notTake = idx!=0?dp[idx - 1][temp]:0;

            int take = 0;
            if (temp >= nums[idx]) {
                take = idx!=0?dp[idx - 1][temp - nums[idx]]:0;
            }

            dp[idx][temp] = take || notTake;
        }
    }

    return dp[n-1][half];
}
};