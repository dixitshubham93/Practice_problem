class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if (n == 1){
            return nums;
        }
        stack<int> st;
        int ngi[n];
        st.push(n-1);
        ngi[n-1] = n;
        for(int i=n-2;i>=0;i--){
            while(st.size() > 0 && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ngi[i] = st.top();
            }
            else{
                ngi[i] = n;
            }
            st.push(i);
        }
        for(int i=0;i<=n-k;i++){
            int j = i;
            while(ngi[j] < i + k){
                j = ngi[j];
            }
            ans.push_back(nums[j]);
        }
        return ans;
    }
};
