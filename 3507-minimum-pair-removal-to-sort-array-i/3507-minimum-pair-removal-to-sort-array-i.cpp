class Solution {
public:
    int SmallestPair(vector<int>&nums){
        int idx = 0;
        int mn = INT_MAX;
        for(int i = 0;i<nums.size()-1;i++){
            if(mn>nums[i]+nums[i+1]){
              mn = nums[i]+nums[i+1];
              idx = i;
            }
        }
        return idx;
    }
    void mergePair(vector<int>&nums ,int i){
        nums[i] += nums[i+1];
        nums.erase(nums.begin() + i + 1);
    }
    int minimumPairRemoval(vector<int>& nums){
       int count = 0;
       while(!is_sorted(nums.begin() , nums.end())){
        mergePair(nums , SmallestPair(nums));
        count++;
       }
       return count;
    }
};