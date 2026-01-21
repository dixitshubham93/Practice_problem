class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
        int x = nums[i];
        if(x==2){
            ans.push_back(-1);
            continue;
        }
        x++;
        x = x>>1;
        x = x&(-x);
        x = ~x;
        ans.push_back(nums[i]&x);
        }

        return ans;
    }
};