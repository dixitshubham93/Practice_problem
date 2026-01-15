class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin() , hBars.end());
        sort(vBars.begin() , vBars.end());

        int hcnt = 0;
        int mhcnt = 0;
        for(int i = 1;i<hBars.size();i++){
            if(hBars[i]-hBars[i-1]==1){
                hcnt++;
                mhcnt = max(mhcnt , hcnt);
            }else{
                hcnt = 0;
            }
        }

        int vcnt = 0;
        int mvcnt = 0;
        for(int i = 1;i<vBars.size();i++){
            if(vBars[i]-vBars[i-1]==1){
                vcnt++;
                mvcnt = max(mvcnt , vcnt);
            }else{
                vcnt = 0;
            }
        }
        int ans = min(mhcnt+2 , mvcnt+2);
        return ans*ans;
    }
};