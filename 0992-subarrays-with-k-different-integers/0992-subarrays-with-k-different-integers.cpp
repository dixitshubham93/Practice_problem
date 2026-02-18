class Solution {
public:
    int atmost(vector<int>& s, int k){
        unordered_map<int,int> mp;
        int ans = 0;
        int start = 0;

        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;

            
            while(mp.size() > k){
                mp[s[start]]--;

                if(mp[s[start]] == 0){
                    mp.erase(s[start]);
                }
                start++;
            }

      
            ans += (i - start + 1);
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& s, int k) {
        return atmost(s, k) - atmost(s, k-1);
    }
};
