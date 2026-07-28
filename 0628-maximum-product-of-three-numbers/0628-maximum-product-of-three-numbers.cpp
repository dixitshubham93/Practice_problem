class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mx1 = INT_MIN;
        int mx2 = INT_MIN;
        int mx3 = INT_MIN;
        int mn1 = INT_MAX;
        int mn2 = INT_MAX;
        int n = nums.size();

        for(int i = 0;i<n;i++){
          if(mx1<nums[i]){
            mx3 = mx2;
            mx2 = mx1;
            mx1 = nums[i];
          }else if(mx2<nums[i]){
            mx3 = mx2;
            mx2 = nums[i];
          }else if(mx3<nums[i]){
            mx3 = nums[i];
          }
          if(mn1>nums[i]){
            mn2 = mn1;
            mn1 = nums[i];
          }else{
            mn2 = min(mn2 , nums[i]);
          }
        }
        
        return max(mx1*mx2*mx3 , mx1*mn1*mn2);

    }
};