class Solution {
public:
    int smallestNumber(int n) {
        int count=0;
        while(n){
            count++;
            n=n/2;
        }
        return pow(2,count)-1;
    }
};