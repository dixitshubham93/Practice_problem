class Solution {
public:
    bool check(long long mid, int k, long long para, vector<long long>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++){
           
        int count = 1;
        int curr_idx = i;
        long long first_val = arr[i];
        long long last_val = arr[i];
        
        for (int j = 1; j < k; j++) {
          
            auto it = lower_bound(arr.begin() + curr_idx + 1, arr.end(), last_val + mid);
            
            if (it == arr.end()) {
                count = -1; break;
            }
            
            last_val = *it;
            curr_idx = distance(arr.begin(), it);
            count++;
        }
        
       
        if (count == k && (para - last_val + first_val) >= mid) return true;
    }
    return false;
}
    int maxDistance(int side, vector<vector<int>>& points, int k){
        long long low = 1;
        long long high = side;
        long long mid = (low+high)/2;
        long long ans = 0;

        vector<long long>arr;

        for(auto& it : points){
            int x = it[0];
            int y = it[1];
            if(y==0){
               arr.push_back(x);
            }else if(x == side){
              arr.push_back(side+y);
            }else if(y==side){
                arr.push_back(1LL*3*side - x);
            }else{
                arr.push_back(1LL*4*side - y);
            }
        }
        sort(arr.begin() , arr.end());
        while(low<=high){
            if(check(mid , k ,1LL*4*side , arr)){
                ans = max ( ans ,mid);
                low = mid+1;
            }else{
                high = mid-1;
            }
            mid = (low+high)/2;
        }
        return ans;
    }
};