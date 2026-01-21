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
        int lowestZero = (~x) & (x + 1);     
        int bitToTurnOff = lowestZero >> 1;   
        ans.push_back(x & (~bitToTurnOff));
        }

        return ans;
    }
};