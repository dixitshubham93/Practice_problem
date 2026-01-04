class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int distinctSum = 0;
        int ans = INT_MAX;
        int s = 0;

        for (int e = 0; e < nums.size(); e++) {
            mp[nums[e]]++;
            if (mp[nums[e]] == 1) {
                distinctSum += nums[e];
            }
            while (distinctSum >= k) {
                ans = min(ans, e - s + 1);

                mp[nums[s]]--;
                if (mp[nums[s]] == 0) {
                    distinctSum -= nums[s];
                }
                s++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
