class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = n;
        int p2 = 0;

        for (int p1 = 0; p1 < n; p1++) {
            while (p2 < n && nums[p2] <= (long long)nums[p1] * k) {
                p2++;
            }
            int windowSize = p2 - p1;
            ans = min(ans, n - windowSize);
        }
        return ans;
    }
};
