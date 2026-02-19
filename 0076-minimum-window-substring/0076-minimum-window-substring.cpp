class Solution {
public:
    bool isvalid( unordered_map<char, int>&freq){
        for(auto[key , val]:freq){
            if(val>0){return false;}
        }
        return true;
    }
    string minWindow(string s, string t){
       unordered_map<char , int>freq;
       for(auto it : t){
        freq[it]++;
       }
       int start = 0;
       int ans = INT_MAX;
       string f ="";
       int l = -1;
       int r = -1;
       for(int i = 0;i<s.size();i++){
        freq[s[i]]--;
        
        if(isvalid(freq)){
            if(ans>i-start+1){
                ans = i - start+1;
                l = start ;
                r = ans;
            }
        }
        while(isvalid(freq)){
             if(ans>i-start+1){
                ans = i - start+1;
                l = start ;
                r = ans;
            }
           freq[s[start]]++;
           start++;
        }
       }
       if(l==-1){return "";}
       return s.substr(l , r);
    }
};