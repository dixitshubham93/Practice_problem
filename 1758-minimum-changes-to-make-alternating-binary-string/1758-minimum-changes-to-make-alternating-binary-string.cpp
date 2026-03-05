class Solution {
public:
    int minOperations(string s){
        int count1 = 0;
        int count2 = 0;
        int ans = 0;
        bool iszero = true;
        bool isone = true;
        for(int i = 0;i<s.size();i++){
            if(iszero&&s[i]!='0'){count1++;}
            else if(!iszero&&s[i]!='1'){count1++;}

             if(isone&&s[i]!='1'){count2++;}
            else if(!isone&&s[i]!='0'){count2++;}
            
            iszero = !iszero;
            isone = !isone;
        }
        
        ans  = min(count1 , count2);
        return ans;
    }
};