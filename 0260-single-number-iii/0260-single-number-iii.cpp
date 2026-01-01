class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
          xr = xr^nums[i];
        }
        int rightmost = xr&(-xr);
        int b1 = 0;
        int b2 = 0;
        for(int i = 0;i<n;i++){
          if(rightmost&nums[i]){
            b1 = b1^nums[i];
          }else{
            b2 = b2^nums[i];
          }
        }
        return {b1 , b2};
    }
};