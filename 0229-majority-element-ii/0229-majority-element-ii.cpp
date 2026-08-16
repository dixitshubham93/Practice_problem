class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int maj1 = 0, maj2 = 1;
        int count1 = 0, count2 = 0;

        for (int x : nums) {
            if (x == maj1) {
                count1++;
            }
            else if (x == maj2) {
                count2++;
            }
            else if (count1 == 0) {
                maj1 = x;
                count1 = 1;
            }
            else if (count2 == 0) {
                maj2 = x;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for (int x : nums) {
            if (x == maj1) count1++;
            else if (x == maj2) count2++;
        }

        vector<int> ans;

        if (count1 > n / 3)
            ans.push_back(maj1);

        if (count2 > n / 3)
            ans.push_back(maj2);

        return ans;
    }
};