class Solution {
public:
    int getMax(vector<int>&freq){
       int mx = 0;
       for(int i =0;i<26;i++){
        mx = max(mx , freq[i]);
       }
       return mx;
    }
    int characterReplacement(string s, int k) {
        vector<int>freq(26);
        int left = 0;
        int ans = 0;
        for(int right = 0;right<s.size();right++){
            freq[s[right]-'A']++;

            int mx = getMax(freq);
            while(right - left + 1 - mx>k){
                freq[s[left]-'A']--;
                left++;
            }
            ans  = max( ans , right - left + 1);      
        }
       return ans;
    }
};