class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)return 0;
       int jum =1;
       int mx = nums[0];
       int next = nums[0];
       int n = nums.size();

       for(int i=1;i<n-1;i++){
        mx = max(mx , i+nums[i]);
        if(next==i){
            jum++;
            next = mx;
        }
       }
       return jum;
    }
};