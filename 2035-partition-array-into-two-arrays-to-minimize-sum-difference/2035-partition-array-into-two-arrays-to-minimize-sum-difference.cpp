class Solution {
public:
    typedef long long ll;

    ll solve(vector<ll>&arr1 , vector<ll>&arr2 , ll total){
        ll n = arr1.size();
        ll m = arr2.size();
        ll ans = LLONG_MAX;
        for(ll i = 0;i<n;i++){
            ll target = total/2 - arr1[i];
            ll lb = lower_bound(arr2.begin() , arr2.end() , target) - arr2.begin();

            if(lb>0){
                ans = min(ans , abs(total - 2*(arr2[lb-1]+arr1[i])));
            }
            if(lb<arr2.size()){
                ans = min(ans , abs(total - 2*(arr2[lb]+arr1[i])));
            }
        }
       return ans;
    }
    int minimumDifference(vector<int>& nums){
        int n = nums.size();
        int half = n/2;
       
        vector<ll>res1[half+1];
        vector<ll>res2[half+1];

        ll total  =accumulate(nums.begin() , nums.end() , 0LL);
        for(int i = 0;i<(1<<half);i++){
            ll sum1 = 0;
            ll sum2 = 0;
            ll count = 0;
         for(int mask = 0;mask<half;mask++){
            if(i&(1<<mask)){
                count++;
                sum1 += nums[mask];
                sum2 += nums[half+mask];
            }
         }
         res1[count].push_back(sum1);
         res2[count].push_back(sum2);
        }
        ll minDiff = LLONG_MAX;

        for(ll i = 1;i<=half;i++){
            sort(res2[half - i].begin() , res2[half- i].end()); 
            minDiff = min(minDiff , solve(res1[i] ,res2[half-i],total));  
        }
        return minDiff;
    }
};