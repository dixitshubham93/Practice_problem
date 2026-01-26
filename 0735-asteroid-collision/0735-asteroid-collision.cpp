class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a){
        
        stack<int> st;

        for (int x : a){

            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && x < 0){
                if (abs(st.top()) < abs(x)) {
                    st.pop(); 
                } 
                else if (abs(st.top()) == abs(x)) {
                    st.pop(); 
                    destroyed = true;
                    break;
                } 
                else {
                    destroyed = true; 
                    break;
                }
            }

            if (!destroyed) st.push(x);
        }

        vector<int> ans(st.size());
        for (int i = (int)st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
