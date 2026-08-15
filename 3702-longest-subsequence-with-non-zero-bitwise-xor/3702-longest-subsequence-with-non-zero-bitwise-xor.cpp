class Solution {
public:
    
    int longestSubsequence(vector<int>& nums) {
      int xr = 0;
      bool ispossible = false;
      for(int x : nums){xr = xr^x;
      if(x){ispossible = true;}}
      int n = nums.size();
      if(xr)return n;
      return ispossible?(n-1):0;
    }
};