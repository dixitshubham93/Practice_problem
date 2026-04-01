class Solution {
public:
    unordered_map<int , unordered_map<int , bool>>dp;
    bool solve(vector<int>&stones,unordered_map<int , int>&mp , int idx , int k){
        if(idx==stones.size()-1){return true;}
        bool ans = false;
        if(dp.count(idx)&&dp[idx].count(k)){return dp[idx][k];}
        for(int i = k-1;i<=k+1;i++){
            if(i<=0){continue;}
            int cor = k+stones[idx];
            if(mp.count(cor)){
            if(solve(stones , mp , mp[cor] , i)){return true;}
            }
        }
        return dp[idx][k]=false;
    }
    bool canCross(vector<int>& stones){
        unordered_map<int , int>mp;
        int n = stones.size();

        for(int i = 0;i<n;i++){
            mp[stones[i]] = i;
        }

      return solve(stones , mp , 0 , 0);
    }
};