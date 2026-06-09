class Solution {
public:

    bool check(long long x , long long totalTrips){
        return x<totalTrips?false:true;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1;
        int mn = *min_element(time.begin() , time.end());
        long long r = 1LL*mn*totalTrips;
        long long mid = l + (r-l)/2;
        while(l<r){
            long long x = 0;
            mid = l + (r-l)/2;
            for(auto& t : time){
              x += mid/t;
            }
            if(!check(x , 1LL*totalTrips)){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }

};