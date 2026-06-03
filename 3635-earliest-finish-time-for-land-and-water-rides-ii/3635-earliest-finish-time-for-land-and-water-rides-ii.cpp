class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int mnel =  1e6;
        int mnew = 1e6;
        int ans = 1e6;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for(int i = 0;i<n;i++){
           mnel = min(mnel , landStartTime[i]+landDuration[i]);
        }
        for(int i = 0;i<m;i++){
           mnew = min(mnew , waterStartTime[i]+waterDuration[i]);
           int newStart = max(mnel , waterStartTime[i]);
           ans = min(ans , newStart + waterDuration[i]);
        }
        
        for(int i = 0;i<n;i++){
           int newStart = max(mnew , landStartTime[i]);
           ans = min(ans , newStart + landDuration[i]);
        }
        return ans;
    }
};