class Solution {
public:
    bool check(string& s){
        if(s=="")return false;
         for(char it : s){
            if(!((it>='a'&&it<='z')||(it>='A'&&it<='Z')||(it>='0'&&it<='9'||it=='_'))){
              return false;
            }
         }
         return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<int , string>>p;
        int n = code.size();
        string cat[4] = {"electronics","grocery","pharmacy", "restaurant"};
        for(int i = 0;i<n;i++){
            if(isActive[i]&&check(code[i])){
                for(int j = 0 ; j<4 ; j++){
                    if(cat[j]==businessLine[i]){
                      p.push_back({j , code[i]});
                      break;
                    }
                }
            }
        }

        sort(p.begin() , p.end());
        vector<string>ans;
        for(auto& it : p){
            ans.push_back(it.second);
        }
        return ans;
    }
};