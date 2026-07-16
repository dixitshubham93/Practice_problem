class Solution {
public:
    long long gcdSum(vector<int>& nums){
    int n = nums.size();
    vector<long long>prefixGcd(n);
    long long temp = 0;
    for(int i = 0;i<n;i++){
        temp = max(temp , 1LL*nums[i]);
        prefixGcd[i] = gcd(temp , nums[i]);
    }
    sort(prefixGcd.begin() , prefixGcd.end());
    long long ans = 0;
    int s = 0;
    int e = n-1;
    while(s<e){
       ans += gcd(prefixGcd[s] , prefixGcd[e]);
       s++;
       e--;
    }
    return ans;
  }
};