class Solution {
public:
    void nextPermutation(vector<int>& nums){
        int idx = -1;
        for(int i = nums.size()-2;i>=0;i--){
             if(nums[i]<nums[i+1]){
                idx = i;
                break;
             }
        }
        if(idx==-1){
             sort(nums.begin(), nums.end()); 
             return ;
        }
        int y = idx+1;
        for(int i = nums.size()-1;i>idx;i--){
             if(nums[idx]<nums[i]){
                if(nums[y]>nums[i]){
                    y =i ;
                }
             }
        }
        swap(nums[y] , nums[idx]);
        sort(nums.begin()+idx+1, nums.end()); 
    }
};