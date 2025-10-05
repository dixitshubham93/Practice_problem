class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int counter[3] = {0};
        
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){counter[0]++;}
            else if(bills[i]==10){
                if(counter[0]<1){return false;}
                counter[0]--;
                counter[1]++;
            }else{
                if(counter[1]>0&&counter[0]>0){
                   counter[1]--;
                   counter[0]--;
                   counter[2]++;

                }else if(counter[0]>2){
                    counter[0]-=3;
                    counter[2]++;
                }else{
                return false;
                }
            }
        }
        return true;
    }
};