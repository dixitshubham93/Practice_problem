class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){

    unordered_map<int , int>mp;
    for(int it : nums){
        mp[it]++;
    }   
    priority_queue<pair<int , int>, vector<pair<int , int>> , greater<>>q;
    int c = 0;
    for(auto it : mp){
      c++;
       q.push({it.second , it.first});
      if(c>k){q.pop();}
     }
     vector<int>ans;
     while(!q.empty()){
        ans.push_back(q.top().second);
        q.pop();
     }
     return ans;
    }
};