class Solution {
    public int countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;

        int[] prefix = new int[n];
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                count++;
            }
            prefix[i] = count;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                int freqTarget =
                        prefix[j] - (i == 0 ? 0 : prefix[i - 1]);

                int len = j - i + 1;
                int half = len / 2;

                if (freqTarget > half) {
                    ans++;
                }
            }
        }

        return ans;
    }
}