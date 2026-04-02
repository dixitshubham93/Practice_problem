class Solution {
public:
    typedef long long ll;
    ll solve(vector<ll>&arr1 , vector<ll>&arr2 , ll total){

        int n = arr1.size();
        int m = arr2.size();
        ll mindiff = LLONG_MAX;

        for(int i = 0;i<n;i++){
            ll target = total/2 - arr1[i];
            int lb = lower_bound(arr2.begin() , arr2.end() , target)-arr2.begin();
        
            if(lb>0){
              mindiff  =min(mindiff , abs(total - 2*(arr1[i]+arr2[lb-1])));
            }
            if(lb<m){
             mindiff  =min(mindiff , abs(total - 2*(arr1[i]+arr2[lb])));
            }
        }
      return mindiff;
    }
    int minimumDifference(vector<int>& nums){

        int n = nums.size();
        int half = n/2;
        vector<vector<ll>>res1(half+1);
        vector<vector<ll>>res2(half+1);

        for(int i = 0;i<(1<<half);i++){
            ll sum1 = 0;
            ll sum2 = 0;
            int count = 0;
            for(int mask = 0;mask<half;mask++){
                if(i&(1<<mask)){
                    count++;
                    sum1+=nums[mask];
                    sum2+=nums[mask+half];
                }
            }
             res1[count].push_back(sum1);
             res2[count].push_back(sum2);
        }    

        ll mindiff = LLONG_MAX;
        ll total = accumulate(nums.begin() , nums.end() , 0LL);

        for(int i = 0;i<=half;i++){
            sort(res2[half-i].begin() , res2[half-i].end());

            mindiff = min(mindiff , solve(res1[i] , res2[half-i] , total));
        }
        return mindiff;
    }
};