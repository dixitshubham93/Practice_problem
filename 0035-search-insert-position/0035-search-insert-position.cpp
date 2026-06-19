class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]<=target){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        if((r-1)>=0&&nums[r-1]==target)return r-1;
        return l;
    }
};