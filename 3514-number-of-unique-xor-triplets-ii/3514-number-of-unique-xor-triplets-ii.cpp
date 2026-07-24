class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums){
        unordered_set<int>st;
        int n = nums.size();
        for(int i = 0;i<n;i++){
          for(int j = i;j<n;j++){
               st.insert(nums[i]^nums[j]);
          }
        }
        unordered_set<int>st2;
        for(int it : st){
            for(int i = 0;i<n;i++){
                st2.insert(it^nums[i]);
            }
        }
       
        return st2.size();
    }
};