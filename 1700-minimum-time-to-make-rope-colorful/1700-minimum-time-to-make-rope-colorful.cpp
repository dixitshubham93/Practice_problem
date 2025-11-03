class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        if(n==1)return 0;
        int p1 = 0;
        int p2 = 1;
        int ans =0;
        while(p2<n){
           if(colors[p1] != colors[p2]){
              p1 = p2;
              p2++;
           }else{
            if(neededTime[p1]<=neededTime[p2]){
                ans+=neededTime[p1];
                p1 = p2;
                p2++;
            }else{
                 ans+=neededTime[p2];
                p2++;
            }
           }
    }
      return ans;
    }
};