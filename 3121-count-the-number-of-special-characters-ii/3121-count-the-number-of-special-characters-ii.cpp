class Solution {
public:
    int numberOfSpecialChars(string word){
        int n = word.size();
        vector<int>up(26) , low(26) , ispossible(26);

        for(int i = 0;i<word.size();i++){
           if(word[i]>'Z'){
             if(up[word[i]-'a']==1){
                ispossible[word[i]-'a'] = 0 ;
                low[word[i]-'a'] = 0;
             }else{
                low[word[i]-'a'] = 1;
             }
           }else{
              if(low[word[i]-'A']==1){
                ispossible[word[i]-'A'] = 1;
              }
                up[word[i]-'A'] = 1;
           }
        }
        int sum = accumulate(ispossible.begin() , ispossible.end() , 0);
        return sum;
    }
};