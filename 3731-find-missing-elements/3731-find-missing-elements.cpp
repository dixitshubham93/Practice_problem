class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int mx = *max_element(nums.begin() , nums.end());
        int mn = *min_element(nums.begin() , nums.end());
        sort(nums.begin() , nums.end());
        int temp = 0;
        for(int i = mn;i<mx;i++)
        {   
            if(temp<nums.size()&&nums[temp]==i){
                temp++;
                continue;
            } 
            ans.push_back(i);
        }
        return ans;
    }
};