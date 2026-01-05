class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = pow(2,n)-1;
        int c = 0;
        vector<vector<int>>ans(subsets+1);

        while(subsets>=0){
             int temp =subsets;
             int l = 0;
             while(temp>0){
                  if(temp&1){
                     ans[c].push_back(nums[l]);
                  }
                     l++;
                     temp = temp>>1;
             }
             c++;
             subsets--;
        }
        return ans;
    }
};