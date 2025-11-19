class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool j = false;
         sort(nums.begin() , nums.end());

        for(int i =0;i<nums.size();i++){
            if(original == nums[i]){
                original *= 2;
            }
        }
       
        return original;
    }
};