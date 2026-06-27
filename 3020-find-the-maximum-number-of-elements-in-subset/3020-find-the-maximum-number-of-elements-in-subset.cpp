class Solution {
public:
    int isPerfectSquareRoot(int n ){
       if(n==1)return 0;
       int root = sqrt(n);
       if(1LL*root*root == n)return root;
       return 0;
    }

    int maximumLength(vector<int>& nums) {
        map<int , int>mp;

        for(int it : nums){
            mp[it]++;
        }
        int ans = 1;

        if(mp.count(1)>0){
            ans = mp[1];
            if(mp[1]%2==0){
                ans--;
            }       
        }

        for(auto it : mp){
            int key = it.first;
            int freq = it.second;
            int root = isPerfectSquareRoot(key);
            if(root!=0){
                   int count = 0;
                   while(mp[root]>=2){
                      count++;
                       root = isPerfectSquareRoot(root);
                   }
                   ans = max(count*2+1 , ans);
            }
        }
        return ans;
    }
};