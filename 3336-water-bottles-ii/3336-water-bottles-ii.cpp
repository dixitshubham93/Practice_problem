class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk =0;
        int empty =0;
        int full  = numBottles;
    
        while(full!=0||empty>=numExchange){
            empty += full;
            drunk+=full;
            full = 0;
           while(empty>=numExchange){

             empty -=numExchange;
             full++;
             numExchange++;
           }
        }

        return drunk;
    }
};