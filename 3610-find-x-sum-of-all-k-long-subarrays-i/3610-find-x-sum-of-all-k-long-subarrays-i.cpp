class Solution {
public:
    int x_sum_function(vector<int>&nums,int s , int e , int x){
        unordered_map<int , int>freq;
        for(int i=s;i<=e;i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int , int>>q;
        for(auto it : freq){
            q.push({it.second , it.first});
        }
        int ans = 0;
        for(int i = 0;i<x;i++){
            if(!q.empty()){
            ans += q.top().first*q.top().second;
            q.pop();
            }
        }
       return ans;
    } 
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>ans(n-k+1 , 0);
        for(int i =0;i<n-k+1;i++){
            ans[i] = x_sum_function(nums , i , i+k-1 , x);
        }
        return ans;
    }
};