class Solution {
public:
    typedef long long ll;
    int minimumPairRemoval(vector<int>&nums) {

        int n = nums.size();

        vector<ll>temp(nums.begin() , nums.end());
        vector<int>nextIdx(n);
        vector<int>preIdx(n);
        set<pair<ll , int>>st;
        int badpair = 0;
        int operations = 0;
        
        for(int i = 0;i<n;i++){
            nextIdx[i] = i+1;
            preIdx[i] = i-1;
        }

        for(int i = 0;i<n-1;i++){
          st.insert({nums[i]+nums[i+1],i});
          if(nums[i]>nums[i+1]){
            badpair++;
          }
        }

        while(badpair>0){
            ll val = st.begin()->first;
            int first = st.begin()->second;
            int second = nextIdx[first];
            int preFirst = preIdx[first];
            int nextSecond = nextIdx[second];
            operations++;
            st.erase(st.begin());
            if(preFirst>=0){
            st.erase({ temp[preFirst] + temp[first] , preFirst});
            st.insert({temp[preFirst] + val , preFirst});
            }
            if(nextSecond<n){
            st.erase({temp[second] + temp[nextSecond] , second});
            st.insert({val + temp[nextSecond], first});
            }
            if(temp[first]>temp[second]){
               badpair--;
            }

            if(preFirst>=0&&temp[preFirst]>temp[first]&&temp[preFirst] <=val){
              badpair--;
            }else if(preFirst>=0&&temp[preFirst]<=temp[first]&&temp[preFirst]>val){
              badpair++;
            }

            if(nextSecond<n&&temp[nextSecond]<temp[second]&&temp[nextSecond]>= val){
              badpair--;
            }else if(nextSecond<n&&temp[nextSecond]>=temp[second]&&temp[nextSecond]<val)  {
              badpair++;
            }
            
            nextIdx[first] = nextSecond;
            if(nextSecond<n){
               preIdx[nextSecond] = first;
            }
            temp[first] += temp[second];
        }
       return operations;
    }
};