class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long long m = mana.size();
        long long n= skill.size();
        vector<long long>pitrr( n , 0);

        for(int i=0;i<m;i++){

            long long curr_po = 1LL*mana[i];
            long long now = pitrr[0];

            for(int j =1;j<n;j++){
                now = max(now+1LL*skill[j-1]*curr_po , pitrr[j]);
            }
            cout<<now<<endl;
            pitrr[n-1] = now + 1LL*skill[n-1]*curr_po;
            for(int j = n-2 ; j>=0 ; j--){
               pitrr[j] = pitrr[j+1] - 1LL*skill[j+1]*curr_po;
            }

        }

        return pitrr[n-1];
    }
};