class Solution {
public:
   int dp[2001];
    bool isPalin(string& s , int i , int j){
        while(i<j){
            if(s[i]!=s[j]){return false;}
            i++;
            j--;
        }
        return true;
    }
    int minCost(string s  , int idx){
        if(idx==s.size()){return 0;}
        if(dp[idx]!=-1){return dp[idx];}
        int mn = INT_MAX;
        for(int i = idx;i<s.size();i++){
            if(isPalin(s , idx , i)){
                mn = min(mn , 1+minCost(s , i+1));
            }
        }
        return dp[idx] = mn;
    }
    int minCut(string s) {
        memset(dp , -1 , sizeof(dp));
        return minCost(s , 0)-1;
    }
};