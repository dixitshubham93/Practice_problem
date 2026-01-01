class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0 ;
        if(n<0)return false;
        while(n){
           count += n&1;
           n =  n>>1;
        }
       return count==1;
    }
};