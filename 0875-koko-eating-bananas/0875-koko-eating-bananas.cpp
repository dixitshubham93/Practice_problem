class Solution {
public:
    bool check(int x , int h ){
        return x>h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin() , piles.end());
        int  l = 0;
        int  r = mx;

        while(l+1<r){
            int mid = l + (r-l)/2;
            int x = 0;
            for(int i : piles){
                x += (i+mid-1)/mid;
                if(x>h)break;
            }

           if(check(x , h)){
            l = mid;
           }else{
            r = mid;
           }
        }
        return r;
    }
};