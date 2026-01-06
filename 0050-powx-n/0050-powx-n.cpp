class Solution {
public:
    
    double Pow(double x, int n) {
        if(n==1){
            return x;
        }else if(n==0){
             return 1;
        }
        
        double l = Pow(x , n/2);
        if(n%2==0)return l*l;
        return l*l*x;
    }
    double myPow(double x, int n){
      double ans = Pow(x , n);

      if(n<0) return 1/ans;
      return ans;
    }
};