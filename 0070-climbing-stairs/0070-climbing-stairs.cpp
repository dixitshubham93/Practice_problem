class Solution {
public:
  
    int climbStairs(int n) {
    vector<int>dp(n+1,0);
    int it1 = 1;
    int it2 = 1;
    for(int i=2;i<=n;i++){
        int x = it1+it2;
        it2 = it1;
        it1 = x;
    }
    return  it1;
    }
};