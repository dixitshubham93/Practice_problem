class Solution {
public:

    bool check(long long trips, long long totalTrips){
        return trips < totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {

        long long l = 0;

        int mn = *min_element(time.begin(), time.end());
        long long r = 1LL * mn * totalTrips;

        while(l + 1 < r){

            long long mid = l + (r - l) / 2;

            long long trips = 0;

            for(auto t : time){
                trips += mid / t;

                if(trips >= totalTrips)
                    break;
            }

            if(check(trips, totalTrips)){
                l = mid;
            }else{
                r = mid;
            }
        }

        return r;
    }
};