class Solution {
public:
    
    int binaryGap(int n){
     int ans = 0;
     int mx =0;
     while(n){
        int bit = n&1;
        n=n>>1;

        if(bit){
            mx = max(ans , mx);
            ans  =1;
        }else if(ans){
            ans++;
        }
     }
     return mx;
    }
};