class Solution {
public:
    
    int MOD = 1e9 + 7;
 
    int concatenatedBinary(int n){
        int temp = 1;
        long long ans = 0;
        int t =1;
        while(temp<=n){      
        ans = (ans<<t|temp)%MOD;
        if(temp == (1<<t)-1){
        t++;
        } 
        temp++;
       }  
        return (int)ans;
    }
};