class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s+s;

        
        int diff1 = 0;
        int diff2 = 0;

        int l = 0;
        int res = INT_MAX;

        for(int r = 0;r<2*n;r++){
            char alt1 = r%2?'0':'1';
            char alt2 = r%2?'1':'0';
            if(ss[r]!=alt1)diff1++;
            if(ss[r]!=alt2)diff2++;

            if(r-l+1>n){
            char alt1 = l%2?'0':'1';
            char alt2 = l%2?'1':'0';
            if(ss[l]!=alt1)diff1--;
            if(ss[l]!=alt2)diff2--;
            l++;
            res = min(res , min(diff1 , diff2));
            }
        }
       return res;
    }
};