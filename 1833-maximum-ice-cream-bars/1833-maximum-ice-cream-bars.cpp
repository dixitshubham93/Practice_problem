class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int>arr(100001, 0);
      
        for(int it : costs){
            arr[it]++;
        }
        int ans = 0;

        for(int i = 1;i<=100000;i++){
            int x = coins/i;
            int take = min(x , arr[i]);
            coins -= take*i;
            ans += take;
            if(coins<=0)break;
        }
      return ans;
    }

};