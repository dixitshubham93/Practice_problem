class Solution {
public:
    typedef long long ll;
    ll solve(vector<ll>& part1 , vector<ll>&part2 , ll total){
        ll mindiff = LLONG_MAX;
        for(int i = 0;i<part1.size();i++){
            ll target = total/2-part1[i];

            int lb = lower_bound(part2.begin() , part2.end() , target)-part2.begin();
            if(lb>0){
                mindiff = min(mindiff , abs(total-2*(part1[i]+part2[lb-1])));
            }
            if(lb<part2.size()){
                mindiff = min(mindiff , abs(total-2*(part1[i]+part2[lb])));
            }
        }
        return mindiff;
    }
    int minimumDifference(vector<int>& nums){
        int n = nums.size();
        int half = n/2;

        vector<vector<ll>>part1(half+ 1);
        vector<vector<ll>>part2(half+ 1);

        for(int i = 0;i<(1<<half);i++){
            ll count = 0;
            ll sum1 = 0;
            ll sum2 = 0;
          for(int mask = 0;mask<half;mask++){
             if(i&(1<<mask)){
               count++;
               sum1 += nums[mask];
               sum2 += nums[mask+half];
             }
           }
           part1[count].push_back(sum1);
           part2[count].push_back(sum2);
        }

        ll mindiff = LLONG_MAX;
        ll total = accumulate(nums.begin() , nums.end(), 0LL);
        for(int i = 0;i<=half;i++){
          sort(part2[i].begin() , part2[i].end());
          mindiff = min(mindiff , solve(part1[half-i] , part2[i] ,total));
        }
      return mindiff;
    }
};