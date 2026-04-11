class Solution {
public:
    int minimumDistance(vector<int>& nums) {
    unordered_map<int , vector<int>>mp;
    
    for(int i = 0;i<nums.size();i++){
     mp[nums[i]].push_back(i);
    }
    int ans = INT_MAX;
    for(auto&[key , elements] : mp){
       if(elements.size()>=3){
        for(int i = 2;i<elements.size();i++){
            ans = min(ans ,abs(elements[i]-elements[i-1])+abs(elements[i]-elements[i-2])+abs(elements[i-2]-elements[i-1] ));
        }
     }
    }
     return ans==INT_MAX?-1:ans;
    }
};