class Solution {
public:
    bool check(int mid, int days, vector<int>& weights) {
        int daysNeeded = 1; 
        int currentLoad = 0;
        
        for (int w : weights) {
            if (currentLoad + w > mid) {
                daysNeeded++;     
                currentLoad = w;   
            } else {
                currentLoad += w;
            }
        }
        
        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
       
        int l = *max_element(weights.begin(), weights.end());
      
        int r = 0;
        for (int w : weights) r += w;
        
        int ans = r;
        
        while (l <= r) {
            int mid = l + (r - l) / 2; 
            
            if (check(mid, days, weights)) {
                ans = mid;     
                r = mid - 1;
            } else {
                l = mid + 1;   
            }
        }
        return ans;
    }
};