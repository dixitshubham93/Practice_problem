class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int s = 0;
        int n = nums.size();
        while(s<n){
            if(nums[s]==-1||s+1 == nums[s]){s++;}
            else if(s+1!=nums[s]){
                if(nums[nums[s]-1]==nums[s]){
                    nums[s] = -1;
                    s++;
                }else{
                    swap(nums[nums[s]-1] , nums[s]);
                }
            }
        }
        for(int i = 0;i<nums.size();i++){if(nums[i]==-1)ans.push_back(i+1);}
        return ans;
    }
};