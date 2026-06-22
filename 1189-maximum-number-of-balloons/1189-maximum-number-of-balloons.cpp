class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(26);

        for(char it : text){
            freq[it-'a']++;
        }
        int ans = min(freq[1] , min(freq[0] ,min(freq['o'-'a']/2, min(freq['n'-'a'],freq['l'-'a']/2))));
        return ans;
    }
};