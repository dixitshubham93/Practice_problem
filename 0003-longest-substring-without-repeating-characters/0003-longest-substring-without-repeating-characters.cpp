class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        unordered_map<char , int>mp;
        int ans = 1;
        int start = 0;
         
        for(int e = 0;e<s.size();e++){
           if(!mp.count(s[e])){
            ans = max(ans , e-start+1);
           }else{
              if(start>mp[s[e]]){
                mp[s[e]] = e;
              }else{
                start = mp[s[e]]+1;
                 mp[s[e]] = e;
              }
           }
        ans = max(ans , e-start+1);
        mp[s[e]] = e;
    }
      return ans;
    }
};