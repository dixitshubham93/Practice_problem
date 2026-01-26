class Solution {
public:
    long long minSumRanges(vector<int>& nums){
    stack<int>st;
    long long ans = 0;
    int n = nums.size();
    for(int i = 0;i<=n;i++){
          while(!st.empty()&&((i==n)||nums[i]<=nums[st.top()])){
            int mid = st.top();
            st.pop();
            int left = st.empty()?mid+1:mid-st.top();
            int right = i - mid;
            ans += 1ll*nums[mid]*left*right;
          }
          if(i<n){
          st.push(i);
          }
    }
    return ans;
    }
     long long maxSumRanges(vector<int>& nums){
    stack<int>st;
    long long ans = 0;
    int n = nums.size();
    for(int i = 0;i<=n;i++){
          while(!st.empty()&&((i==n)||nums[i]>=nums[st.top()])){
            int mid = st.top();
            st.pop();
            int left = st.empty()?mid+1:mid-st.top();
            int right = i - mid;
            ans += 1ll*nums[mid]*left*right;
          }
        if(i<n){
          st.push(i);
          }
    }
    return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return maxSumRanges(nums) - minSumRanges(nums);
    }
};