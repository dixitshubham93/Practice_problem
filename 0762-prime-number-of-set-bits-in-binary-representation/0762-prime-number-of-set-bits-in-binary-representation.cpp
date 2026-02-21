class Solution {
public:
    int b(int x){
    int ans = 0;
    while(x){
        int bit = x&1;
         if(bit){
            ans++;
        }
        x = x>>1;
    }
    return ans;
}
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}
    int countPrimeSetBits(int left, int right) {
    int start = 0;
	for(int i = left;i<=right;i++){
	    int temp = 0;
	   
	        if(isPrime(b(i))){
	            start++;
	        }
	    }
	    return start;
	}
    
};