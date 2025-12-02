class Solution {
public:
    long long MOD = 1e9+7;
    
    int countTrapezoids(vector<vector<int>>& points) {
     map<int , int>mp;

     for(auto& it : points){
        mp[it[1]]++;
     }
     
     long long ans  = 0;
     int count  = 0;
     vector<long long>temp;
     for(auto i : mp){
       if(i.second>=2){
         temp.push_back((1LL*i.second*(i.second-1)/2)%MOD);
       }
     }

     long long prefix = 0;
     for(int i=temp.size()-1;i>=0;i--){
       ans = (ans + (temp[i] * prefix) % MOD) % MOD;
       prefix += temp[i];
     }
     
      return (int)ans;
    }
};