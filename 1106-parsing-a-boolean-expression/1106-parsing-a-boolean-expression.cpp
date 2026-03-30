class Solution {
public:
    char solve(char op , vector<char>& vec){
        if(op=='!'){
            return vec[0]=='t'?'f':'t';
        }else if(op=='&'){
            for(int i = 0;i<vec.size();i++){
                if(vec[i]=='f'){return 'f';}
            }
            return 't';
        }else if(op=='|'){
             for(int i = 0;i<vec.size();i++){
                if(vec[i]=='t'){return 't';}
            }
            return 'f';
        }
      return 't';
    }
    bool parseBoolExpr(string exp) {
        stack<char>st;
        int n = exp.size();

        for(int i = 0;i<n;i++){
          if(exp[i]==',')continue;

          if(exp[i]==')'){
            vector<char>vec;
            while(st.top()!='('){
               vec.push_back(st.top());
               st.pop();
            }
            st.pop();
            char op = st.top();
            st.pop();
            st.push(solve(op , vec));
          }else{
          st.push(exp[i]);
          }
        }
       return st.top()=='t'?true:false;
    }
};