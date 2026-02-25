class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int max=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]){count++;
            if(max<count){max=count;}}
            else{count=0;}
        }
        return max;
    }
};