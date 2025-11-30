class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for (int x : nums) sum += x;

        int target = sum % p;
        if (target == 0) return 0;  // already divisible

        unordered_map<int,int> mp;
        mp[0] = -1;  // prefix sum 0 at index -1

        int n = nums.size();
        int ans = n;
        long long prefix = 0;

        for (int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % p;  // always mod p

            int need = (int)((prefix - target + p) % p);  // what previous prefix we need
            if (mp.find(need) != mp.end()) {
                ans = min(ans, i - mp[need]);
            }
            mp[(int)prefix] = i;  // store last index for this prefix mod
        }

        return ans == n ? -1 : ans;
    }
};
