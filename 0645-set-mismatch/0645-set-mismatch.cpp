class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int sum = (n+1)*n/2;
        int temp = 0;
        int repeted = 0;

        for(int i = 0;i<n-1;i++){
            temp += nums[i];
            if(nums[i]==nums[i+1]){repeted = nums[i];}
        }
        temp += nums[n-1];

        int r_m = temp - sum;
         
        return {repeted, repeted - r_m};
    }
};