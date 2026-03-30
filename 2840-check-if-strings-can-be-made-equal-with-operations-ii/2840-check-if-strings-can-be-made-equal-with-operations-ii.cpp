class Solution {
public:
    bool checkStrings(string s1, string s2) {

        vector<int>odd(26);
        vector<int>even(26);
        int n = s1.size();
       for(int i = 0;i<n;i++){
        if(i%2){
            odd[s1[i]-'a']++;
            odd[s2[i]-'a']--;
        }else{
            even[s1[i]-'a']++;
            even[s2[i]-'a']--;
        }
       }
       for(int i = 0;i<26;i++){
            if(odd[i]!=0||even[i]!=0){return false;}
       }

        return true;
    }
};