class Solution {
public:
   int memo[32][2][2];
   int solve(int idx ,int tight , int diff , string& s){
     if(idx>=s.size()){return diff;}
     if(memo[idx][tight][diff]!=-1)return memo[idx][tight][diff];
     int limit = tight==1?(s[idx]-'0'):9;
     int valid[7] = {0 ,1 , 2 , 5 , 6 , 8 , 9 };
     int ans = 0;
     for(int d : valid){
        if(d>limit)break;
        int nextdiff = (diff==1||(d==2||d==5||d==6||d==9))?1:0;
        ans += solve(idx+1 , (tight&&(d==limit))?1:0 , nextdiff , s);
     }
     return memo[idx][tight][diff]=ans;
   }
    
    int rotatedDigits(int n) {
    memset(memo , -1 , sizeof(memo));
    string s = to_string(n);
    return solve(0 , 1 , 0 , s);
    }
};