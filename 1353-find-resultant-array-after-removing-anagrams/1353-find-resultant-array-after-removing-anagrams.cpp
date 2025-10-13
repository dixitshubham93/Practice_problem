class Solution {
public:
   bool compare(string s1 , string s2){

    if(s1.size()!=s2.size()){return false;}

   vector<int>temp(26,0);

   for(int i=0;i<s1.size();i++){
    temp[s1[i]-'a']++;
    temp[s2[i]-'a']--;
   }
   for(int i=0;i<26;i++){
    if(temp[i]!=0)return false;
   }
   return true;
   }
    vector<string> removeAnagrams(vector<string>& words){
       int n = words.size();
       string word1=words[0];
       vector<string>ans;
       ans.push_back(word1);
       for(int i =1;i<n;i++){
        if(!compare(word1,words[i])){
          word1 = words[i];
          ans.push_back(word1);
        }
       }
      return ans;
    }
};