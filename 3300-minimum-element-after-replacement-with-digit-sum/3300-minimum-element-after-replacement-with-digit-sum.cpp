class Solution {
public:
    int sum(int num){

        int count = 0;
        while(num){
            count += num%10;
            num = num/10;
        }
        
        return count;
    }
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            ans = min(ans , sum(nums[i]));
        }
        return ans;
    }
};