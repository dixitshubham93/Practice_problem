class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0 ;
        int n = nums.size();
        for(int i = 0;i<n;i++){
                sum += nums[i];
        }
        int ans = 0;
        int temp = 0;
        for(int i = 0;i<n-1;i++){
         temp += nums[i];
         int temp1 = temp - (sum - temp);
         if(temp1%2==0){
            ans++;
         }
        }
        return ans;
    }
};