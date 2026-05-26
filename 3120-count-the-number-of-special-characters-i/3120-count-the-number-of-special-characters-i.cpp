class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int>up(26,0);
        vector<int>low(26,0);

        for(int i =0;i<s.size();i++){
            if(s[i]>'Z'){
                low[s[i]-'a']=1;
            }else{
                up[s[i]-'A']=1;
            }
        }
        int count = 0;
        for(int i = 0;i<26;i++){
            if(up[i]&&low[i]){count++;}
        }
        return count;
    }
};