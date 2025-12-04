class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int , int>mp;
        for(int i=0;i<speed.size();i++){
            mp[position[i]] = speed[i];
        }
        int ans  = 0;
        double curr = 0.0;
        for(auto it = mp.rbegin() ; it!=mp.rend();it++)
        {
            double temp = ((double)target-(double)it->first)/(double)it->second;
            if(curr<temp){
                ans++;
                curr = temp;
            }
        }
        return ans;
    }
};