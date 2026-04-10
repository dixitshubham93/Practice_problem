class Solution {
public:
   long long MOD  = 1e9+7;
   long long binaryExponential(long long a , long long b){
    if(b==0){return 1;}
    long long half = binaryExponential( a , b/2);
    long long result = (half%MOD*half%MOD)%MOD;
    if(b%2==1){
        result = (result%MOD*a%MOD)%MOD;
    }
    return result;
   }
    
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries){

       unordered_map<int , vector<vector<int>>>mp;
       int n = nums.size();

       int blocksize  = (int)sqrt(n);

       for(auto& it : queries){
        if(it[2]>blocksize){
            for(int i = it[0];i<=it[1];i+=it[2]){
                nums[i] = (nums[i]%MOD*it[3]%MOD)%MOD;
            }
        }else{
            mp[it[2]].push_back(it);
        }
       }

       for(auto&[k , allqueries]:mp){
          vector<int>diff(n , 1);
          for(auto&it : allqueries){
            int l = it[0];
            int r = it[1];
            int v = it[3];
            diff[l] = (diff[l]%MOD*v%MOD)%MOD;
            int steps = (r-l)/k;
            int right = l + (steps + 1)*k;
            if(right<n){
             diff[right] = (diff[right]%MOD*binaryExponential(v , MOD-2)%MOD)%MOD;
            }
          }
          for(int i = 0;i<n;i++){
            if(i-k>=0){
            diff[i] = (diff[i-k]%MOD*diff[i]%MOD)%MOD;
            }         
            nums[i] = (nums[i]%MOD*diff[i]%MOD)%MOD;
          }
       }
       int ans = 0;

       for(int i = 0;i<n;i++){
        ans = ans^nums[i];
       }
      return ans;
    }
};