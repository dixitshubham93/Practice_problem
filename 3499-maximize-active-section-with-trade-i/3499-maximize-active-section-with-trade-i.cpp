class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int Co = 0;
        int n = s.size();
        int temp = 0;
        vector<int>prefix(n);
        vector<int>suffix(n);

        
        for(int i = 0;i<n;i++){
            if(s[i]=='1'){
             Co++;
           }
            if(i!=0&&s[i-1]=='1'&&s[i]=='0'){
                temp = 0;
            }
            if(s[i]=='0'){
                temp++;
            }
            prefix[i] = temp;
        }
        temp = 0;
        for(int i = n-1;i>=0;i--){
            if(i!=(n-1)&&s[i+1]=='1'&&s[i]=='0'){
                temp = 0;
            }
            if(s[i]=='0'){
                temp++;
            }
            suffix[i] = temp;
        }


        int mx = 0;
         for(int i = 0;i<n;i++){
            if(s[i]=='1'&&i!=0&&prefix[i]!=0&&suffix[i]!=0){
            mx = max(mx , prefix[i]+suffix[i]);
           }
        }
        return Co + mx;     
    }
};