class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid = (s+e)/2;
        int ans = 0;
        while(s<e){
           if(nums[0]<=nums[mid]){
            s = mid+1;
           }else{
            ans = mid;
            e = mid;
           }
            mid = (s+e)/2;
        }
        return min(nums[mid],nums[ans]);
    }
};