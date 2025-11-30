class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>minprefix(k ,LLONG_MAX);
        minprefix[0]=0;
        long long prefix = 0;
        long long ans = LLONG_MIN;

        for(int i=0;i<n;i++){
            prefix+= nums[i];
            if(minprefix[(i+1)%k]!=LLONG_MAX){
            ans = max(ans , prefix - minprefix[(i+1)%k]);
            }
            minprefix[(i+1)%k] = min(minprefix[(i+1)%k] , prefix);
        }
        return ans;
    }
};