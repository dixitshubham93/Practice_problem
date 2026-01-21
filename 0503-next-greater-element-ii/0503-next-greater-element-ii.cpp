class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i  = 2*n-1;i>=0;i--){
           if(st.empty()){
            ans[i%n] = -1; 
           }
           while(!st.empty()&&nums[i%n]>=st.top()){
                 st.pop();
           }
           if(st.empty()){
             ans[i%n] = -1; 
           }else{
             ans[i%n] = st.top(); 
           }
           st.push(nums[i%n]);
        }
      return ans;
    }
};