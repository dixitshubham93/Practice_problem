class Solution {
public:
   int predicate(int x, int bound) {
        if (bound <= x)
            return 0;
        return 1;
    }

    int findMin(vector<int>& nums) {
        int n = nums.size();
        int comparator = nums[0];
        int s = 0;
        int e = nums.size() - 1;
        if (nums[0] <= nums[n - 1]) {
            return nums[0];
        }
        int l = 0;
        int r = n - 1;
        int mid = l + (r - l) / 2;
         while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (predicate(nums[mid], nums[0]) == 0) {
              
                l = mid;
            } 
            else {
                r = mid;
            }
        }
        return min(nums[l],nums[r]);
    }
};