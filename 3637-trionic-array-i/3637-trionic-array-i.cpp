class Solution {
public:
    bool isTrionic(vector<int>& nums){
           int count = 0;
     
           if(nums[0]>=nums[1]||nums[nums.size()-2]>=nums[nums.size()-1]){
            return false;
           }
           for(int i = 1;i<nums.size()-1;i++){
            if(nums[i-1]>nums[i]&&nums[i]<nums[i+1]){
                count++;
            }else if(nums[i-1]<nums[i]&&nums[i]>nums[i+1]){
                count++;
            }else if(nums[i]==nums[i+1]){
                return false;
            }
           }
        
       return count==2?true:false;
    }
};