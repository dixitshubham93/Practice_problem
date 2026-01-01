class Solution {
public:
    int divide(int dividend, int divisor){

    if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

    bool sign = (dividend > 0) ^ (divisor > 0);
    int ans = 0;
    int n   = abs(dividend);
    divisor = abs(divisor);
    

    while(n >= divisor){
        int count = 0;
        while(n>=divisor*(pow(2,count+1))){
            count++;
        }
        ans += pow(2,count);
        n = n - divisor*(pow(2,count));
    }
     return sign ? -ans : ans;

    }
};