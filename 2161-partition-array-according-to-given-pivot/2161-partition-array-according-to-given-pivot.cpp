class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> q1;
        int count = 0;
        queue<int> q2;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == pivot) {
                count++;
            } else if (nums[i] > pivot) {
                q2.push(nums[i]);
            } else {
                q1.push(nums[i]);
            }
        }
        int j = 0;

        while (!q1.empty()) {
            nums[j] = q1.front();
            q1.pop();
            j++;
        }
        while (count--) {
            nums[j] = pivot;
            j++;
        }
        while (!q2.empty()) {
            nums[j] = q2.front();
            q2.pop();
            j++;
        }
        return nums;
    }
};