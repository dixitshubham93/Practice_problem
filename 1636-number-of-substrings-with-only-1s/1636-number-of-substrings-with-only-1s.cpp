class Solution {
public:
    long long MOD = 1e9 + 7;
    int numSub(string s) {
        long long count = 0;
        long long ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                ans += (count*(count+1)/2)%MOD;
                count=0;}else{
                count = (count+1)%MOD;     
            }
        }
         ans += (count*(count+1)/2)%MOD;
        return (int)ans;
    }
};