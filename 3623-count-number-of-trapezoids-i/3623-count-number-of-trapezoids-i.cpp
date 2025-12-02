class Solution {
public:
    long long MOD = 1e9+7;
    long long nCr(int n, int r) {
    if (r > n) return 0;
    if (r > n - r) r = n - r;  // because C(n, r) = C(n, n-r)

    long long ans = 1;
    for (int i = 1; i <= r; i++) {
        ans = (ans * (n - i + 1) / i)%MOD;
    }
    return ans;
}

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
         temp.push_back(nCr(i.second,2));
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