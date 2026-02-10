class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int , int>mp;
        int s = 0;
        int ans = 0;

        for(int e = 0;e<fruits.size();e++){
            mp[fruits[e]]++;
           
            while(mp.size()>2){
              mp[fruits[s]]--;
              if(mp[fruits[s]]==0){
                mp.erase(fruits[s]);
              }
              s++;
            }
            ans  = max(ans , e-s+1);
        }
        return ans;
    }

};