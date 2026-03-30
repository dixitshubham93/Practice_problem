class Solution {
public:

    bool isPalin(string s){
     int l = 0;
     int r = s.size()-1;
     while(l<r){
        if(s[l]!=s[r]){
         return false;
        }
        l++;
        r--;
     }
     return true;
    }
    void solve(string& s , vector<string>&path , vector<vector<string>>&ans, int idx){
        
        if(idx >= s.size()){
            ans.push_back(path);
        }
        for(int i = 1;(idx+i)<=s.size();i++){
            if(isPalin(s.substr(idx , i))){
                path.push_back(s.substr(idx , i));
                solve(s , path , ans , i+idx);
                path.pop_back();
            }
        }
     return;
    }             
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        solve(s , path , ans , 0);
        return ans;
    }
};