class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin() , potions.end());
        int n = spells.size();
        int x = potions.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            long long target;
            if(success%spells[i]==0){
             target= success/spells[i];
            }else{
                target= success/spells[i]+1;
            }
            auto it  =lower_bound(potions.begin() , potions.end(),target);
            if(it==potions.end()){ans[i] = 0;}
            else{
                ans[i] =(x-(it-potions.begin()));
            }
        }
        return ans;
    }
};