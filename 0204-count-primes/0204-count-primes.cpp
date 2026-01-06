class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)return 0;
       vector<int>prime(n+1,1);
       
       prime[0] = 0;
       prime[1] = 0;

       for(int i= 2;i<=n;i++){
           if(prime[i]==1){
            for(int j = 2*i;j<=n;j+=i){
                prime[j] = 0;
            }
           }
       }
       int count = 0;
       for(int i = 2;i<n;i++){
        if(prime[i]==1){
            count++;
        }
       }
       return count;
    }
};