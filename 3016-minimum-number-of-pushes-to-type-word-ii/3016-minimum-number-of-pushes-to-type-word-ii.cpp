class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(int i = 0;i<word.size();i++){          
        freq[word[i]-'a']++;
        }

        sort(freq.rbegin() , freq.rend());

        int ans  = 0;
        for(int i = 0;i<26;i++){
        ans += freq[i]*((i+8)/8);
        }

        return ans;
    }
};