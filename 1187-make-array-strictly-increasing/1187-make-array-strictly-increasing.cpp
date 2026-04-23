class Solution {
public:
    unordered_map<int , unordered_map<int , int>>dp;
    int solve(int idx , int prev , vector<int>&arr1 , vector<int>&arr2){
        if(idx>=arr1.size()){return 0;}
        int take = 1e9;
        if(dp.count(idx)!=0&&dp[idx].count(prev)!=0)return dp[idx][prev];
        if(prev<arr1[idx]){
            take = solve(idx+1 , arr1[idx] ,arr1 , arr2);
        }
        int notTake = 1e9;
        auto it = upper_bound(arr2.begin() , arr2.end() , prev);
        if(it!=arr2.end()){
            int index = it-arr2.begin();
            notTake = 1 + solve(idx+1, arr2[index] , arr1 , arr2);
        }
      return dp[idx][prev] = min(take , notTake);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
      sort(arr2.begin() , arr2.end());
      int ans = solve(0 , INT_MIN , arr1 , arr2);
      return ans==1e9?-1:ans;
    }
};