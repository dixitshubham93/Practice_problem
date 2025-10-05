class Solution {
public:
    bool checkValidString(string s) {
        
        int maxi = 0;
        int mini = 0;

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '('){
                maxi++;
                mini++;
            }
            else if(s[i] == ')'){
                maxi--;
                mini--;
            }
            else{ 
                maxi++;
                mini--; 
            }
            
            if(maxi < 0) return false;
            
            if(mini < 0) mini = 0; 
        }

        return mini <= 0; 
    }
};