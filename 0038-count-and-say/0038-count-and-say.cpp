

class Solution {
public:
    string solve(string s ){
        char c =s[0];
        int f = 1;
        string ans = "";
        for(int  i = 1;i<s.size();i++){
            if(s[i]==c){
                f++;
            }else{
              ans += to_string(f); 
              ans += c;            
              f = 1;
              c = s[i];
            }
        }
        ans += to_string(f); 
        ans += c;             
        return ans;
    }
    string countAndSay(int n) {
        if(n==1)return "1";
        string ans  ="1";
        for(int i=1;i<n;i++){
           ans = solve(ans);
        }
      return ans;
    }
};
