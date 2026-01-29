class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        set<int>st;
        int n = nums.size();
        vector<int>ans;

        int s = 0;
        int e = 0;

        while(e<n){
            mp[nums[e]]++;
            if(st.count(nums[e])==0){
                st.insert(nums[e]);
            }
            e++;
            if(e<k){continue;}
            ans.push_back(*st.rbegin());
            mp[nums[s]]--;
            if(mp[nums[s]]==0){
                st.erase(nums[s]);
            }
            s++;
        }
        return ans;
    }
};