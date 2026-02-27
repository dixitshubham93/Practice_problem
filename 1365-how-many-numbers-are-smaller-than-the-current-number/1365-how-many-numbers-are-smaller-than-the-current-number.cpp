class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums){
        vector<int>temp = nums;
        sort(temp.begin() , temp.end());
        int n = nums.size();
        vector<int>ans(n);
        int s = 0;

        while(s<n){
            ans[s] = lower_bound(temp.begin(),temp.end() , nums[s]) - temp.begin();
            s++;
        }
       
        return ans;
    }
};