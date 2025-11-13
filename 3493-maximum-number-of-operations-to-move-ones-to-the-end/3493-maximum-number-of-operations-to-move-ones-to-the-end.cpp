class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int count =0;
        if(s[0]=='1'){count++;}
        for(int i=1;i<s.size();i++){
            if(s[i]=='0'&&s[i-1]=='1'){ans += count;}
            else if(s[i]=='1'){count++;}
        }
        return ans ;
    }
};