class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int x = nums[0];
        int n = nums.size();

        for(int i =1;i<n;i++){
            if(nums[i] == (nums[i-1]+1)){
                x += nums[i];
            }else{
                break;
            }
        }
        sort(nums.begin() , nums.end());
        for(int i = 0;i<n;i++){
            if(nums[i]<x)continue;
            if(nums[i]==x){
                  x++;
            }else{
                return x;
            }
        }
        return x;
    }
};