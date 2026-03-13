class Solution {
public:
    bool ispossible(long long mid , vector<int>& wt , int h){
           int temp = 0;
           for(int x : wt){
            temp += sqrt(mid*2/x + 0.25) - 0.5;
            if(temp>=h){return true;}  
           }
           return temp>=h;
    }
    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        long long s = 1;
        long long e = 1ll*wt[0]*(mh*1ll*(mh+1)/2);
        long long mid = (s+e)/2;
        long long result = 0;
         while(s<=e){
            if(ispossible(mid , wt , mh)){
                result = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
            mid = (e-s)/2 + s;
         }
         return result;
    }
};