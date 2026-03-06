class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int isone  = false;
        for(int i = n-1;i>=0;i--){
            if(s[i]=='1'){isone=true;}
            else if(isone&&s[i]=='0'){return false;}
        }
        return true;
    }
};