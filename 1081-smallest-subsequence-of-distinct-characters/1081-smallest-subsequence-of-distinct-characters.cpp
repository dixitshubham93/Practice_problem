class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool>visited(26 , false);
        vector<int>lastIndex(26,-1);
        int n = s.size();

        for(int i = 0;i<n;i++){
         lastIndex[s[i]-'a']= i;
        }
        string ans ="";
        stack<char>st;
        int i = 0;
        for(char it : s){
            if(st.empty()){
                visited[it-'a'] = true;
                st.push(it);
            }else if(visited[it-'a']){
                i++;
                continue;
            }
            else{
                while(!st.empty()&&st.top()>it&&lastIndex[st.top()-'a']>i){
                  visited[st.top()-'a'] = false;
                  st.pop();
                }
                visited[it-'a'] = true;
                st.push(it);
            }
            i++;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};