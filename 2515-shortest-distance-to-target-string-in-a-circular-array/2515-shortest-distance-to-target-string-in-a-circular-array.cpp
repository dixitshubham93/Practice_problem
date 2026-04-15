class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if(words[startIndex]==target){return 0;}
        int n = words.size();
        int ans = n+1;
        for(int i = 0;i<n;i++){
            if(words[i]==target){
                ans  = min(ans , min(abs(i - startIndex) , n - abs(i - startIndex)));
            }
        }
        return ans==n+1?-1:ans;
    }
};