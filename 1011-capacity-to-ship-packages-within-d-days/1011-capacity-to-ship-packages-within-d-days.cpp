class Solution {
public:
    bool check(int x , int days){
        return x>days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin() , weights.end()) - 1;
        int sum = accumulate(weights.begin() , weights.end() , 0);
        int r = sum;

        while(l+1<r){
            int mid = l + (r-l)/2;
            
            int x = 0;
            int temp = 0;
            for(int i = 0;i<weights.size();i++){
               if(temp+weights[i]>mid){
                  temp = weights[i];
                  x++;
               }else{
                temp += weights[i];
               }
            }
            if(temp>0)x++;
            if(check(x , days)){
                l = mid;
            }else{
                r = mid;
            }
        }
        return r;
    }
};