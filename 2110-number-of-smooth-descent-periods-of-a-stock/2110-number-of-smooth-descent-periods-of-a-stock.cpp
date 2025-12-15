class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
       int n = prices.size();
       long long counter = 0;
       long long ans = n;
       for(int i = 0;i<n-1;i++){
        if((prices[i]-prices[i+1])==1){
            if(counter ==0){
                counter+=2*1LL;
            }else{
                counter++;
            }
        }else{
            ans += 1LL*(counter*(counter-1))/2;
            counter = 0;
        }
       }
      
       ans += 1LL*(counter*(counter-1))/2;        
      return ans;
    }
};