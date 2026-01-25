class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int e = 0;
        int s = 0;
        int mn = INT_MAX;
        k--;
        for(int i = 0;i<nums.size();i++){
            if(i<k){e++;
            continue;}
            else{
                mn = min(mn , nums[e]  - nums[s]);
                e++;
                s++;
            }
        }
        return mn;
    }
};