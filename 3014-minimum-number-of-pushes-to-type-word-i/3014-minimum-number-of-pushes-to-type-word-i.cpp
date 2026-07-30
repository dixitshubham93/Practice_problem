class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char , int>mp;
        for(int i = 0;i<word.size();i++){
            if(mp.count(word[i])==0){
                mp[word[i]] = (mp.size())/8+1;
            }
        }
        int ans  = 0;
        for(int i = 0;i<word.size();i++){
            ans += mp[word[i]];
        }
        return ans;
    }
};