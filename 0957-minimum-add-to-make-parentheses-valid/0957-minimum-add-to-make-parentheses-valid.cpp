class Solution {
public:
    int minAddToMakeValid(string s) {
        int count =0;
        int brakets = 0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='('){
                brakets++;
            }else{
                brakets--;
            }
            if(brakets<0){
                brakets = 0;
                count++;
            }
        }
        return count + abs(brakets);
    }
};