class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = nums[0];
        int e = min_element(nums.begin()+1 , nums.end())-nums.begin();
        int second  = nums[e];
        nums[e] = INT_MAX;
        int third = *min_element(nums.begin()+1 , nums.end());
        return first + second + third;
    }
};