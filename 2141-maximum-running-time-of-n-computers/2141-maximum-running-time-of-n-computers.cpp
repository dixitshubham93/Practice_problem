class Solution {
public:
    bool check(vector<int>&bt ,int n ,long long k){
        long long temp = 0;

        for(int i : bt){
            temp += min(k , i*1LL);
            if(n*k<=temp){
                return true;
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& bt) {
      sort(bt.rbegin() , bt.rend());
      long long low = 0;
      long long high = 1e14;
      long long ans = 0;

      while(low<=high){
        long long mid = low + (high-low)/2;
        
        if(check(bt,n,mid)){
            ans = max(mid , ans);   
            low = mid+1;
        }else{
            high  = mid-1;
        }
      }
      
      return ans; 
    }
};