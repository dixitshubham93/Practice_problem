class Solution {
public:
    
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        unordered_set<string>st;
        for(auto& it : dictionary){
            st.insert(it);
        } 
        vector<string>arr2;
        for(auto& it : queries){
            if(st.find(it)!=st.end()){
                 arr2.push_back(it);}
            else{
               for(auto& p1:dictionary){
                 int n = p1.size();
                 int mis = 0;
                 for(int i = 0;i<n;i++){
                    if(p1[i]!=it[i]){
                        mis++;
                    }
                    if(mis>2){
                        break;
                    }
                 }
                 if(mis<=2){
                   arr2.push_back(it);
                   break;
                 }
               }
            }
        }
       return arr2;
    }
};