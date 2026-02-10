class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int allowed = 0;
        int s =0;
        int n = nums.size();
        for(int e = 0;e<n;e++){
            if(nums[e]==1){
                ans = max(ans , e-s+1);
            }else{
                allowed++;
                while(allowed>k){
                    if(nums[s]==0){
                        allowed--;
                        s++;
                        break;
                    }
                      s++;
                }
            }
             ans = max(ans , e-s+1);
        }
        return ans;
    }
};