class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int full = numBottles;
        int empty =0;
        while((empty>=numExchange||full!=0)){
           ans+= full;
           empty += full;
           full = empty/numExchange;
           empty = empty%numExchange;
        }
        return ans;
    }
};