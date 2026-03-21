class Solution{
public:
    vector<vector<int>>dp;
    
    bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2 != 0) return false;

    int n = nums.size();
    int half = sum / 2;

    vector<vector<int>> dp(n + 1, vector<int>(half + 1, 0));

    // Base case
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Bottom-up
    for (int idx = n - 1; idx >= 0; idx--) {
        for (int temp = 0; temp <= half; temp++) {

            int notTake = dp[idx + 1][temp];

            int take = 0;
            if (temp >= nums[idx]) {
                take = dp[idx + 1][temp - nums[idx]];
            }

            dp[idx][temp] = take || notTake;
        }
    }

    return dp[0][half];
}
};