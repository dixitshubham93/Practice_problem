class Solution {
public:
    int product(int t){
        int pro =  1;
        while(t){
            pro *=t%10;
            t = t/10;
        }
        return pro;
    }

    int smallestNumber(int n, int t) {
      
       while(true){
        int temp = product(n);
        if(temp%t==0){return n;}
        n++;
       }
       return 0;
    }
};