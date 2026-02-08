class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int>freq;
        freq[0] = 1;
        int count = 0;
        int preSum = 0;
        for(int x : nums){
            preSum += x;
            if(freq.count(preSum - k)){
                count += freq[preSum - k];
            }
            freq[preSum]++;
        }
        return count;
    }
};