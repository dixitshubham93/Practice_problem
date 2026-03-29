class Solution {
public:
    bool checkStrings(string s1, string s2) {

        vector<int>s1odd(26);
        vector<int>s1even(26);
        vector<int>s2odd(26);
        vector<int>s2even(26);
        int n = s1.size();
       for(int i = 0;i<n;i++){
        if(i%2){
            s1odd[s1[i]-'a']++;
        }else{
            s1even[s1[i]-'a']++;
        }
       }
       for(int i = 0;i<n;i++){
        if(i%2){
            s2odd[s2[i]-'a']++;
        }else{
            s2even[s2[i]-'a']++;
        }
       }

        return s1odd==s2odd&&s1even==s2even;
    }
};