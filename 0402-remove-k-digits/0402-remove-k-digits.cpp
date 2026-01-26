class Solution {
public:
    string removeKdigits(string num, int k){

        stack<char>st;
        int n = num.size();
        if(n<k){return "0";}
        else if(k==0){return num;}
        
        for(int i = 0;i<n;i++){
         while(!st.empty()&&num[i]<st.top()&&k){
                k--;
                st.pop();
          }
          st.push(num[i]);
        }

        while(k&&!st.empty()){
           k--;
           st.pop();
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin() , ans.end());

        while(!ans.empty()&&ans[0]=='0'){
            ans.erase(ans.begin());
        }
       return ans == ""?"0":ans;
    }
};