class Solution {
public:
    int minimumDistance(vector<int>& nums){
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 0;i<n;i++){
             int k = -1;
             int third = -1;
            for(int j = i+1;j<n;j++){
              if(nums[i]==nums[j]){
                if(k==-1){
                    k = j;
                }else if(third==-1){
                   ans = min(ans , abs(i - j) + abs(j - k) + abs(k - i));
                   break;
                }
              }
            }
        }
            return ans==INT_MAX?-1:ans;
    }
};