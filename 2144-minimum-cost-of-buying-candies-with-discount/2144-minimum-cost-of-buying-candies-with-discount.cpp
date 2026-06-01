class Solution {
public:
    int minimumCost(vector<int>& cost) {
         sort(cost.rbegin() , cost.rend());
         int sum = 0;
         int n = cost.size();
         int i = 0;
         while(i<n){       
          sum += cost[i];
          if((i+1)<n){
            sum += cost[i+1];
          }
          i+=3;
         }
         return sum;
    }
};