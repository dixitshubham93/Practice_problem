class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       unordered_set<int>st;
       int n = A.size();
       vector<int>ans(n,0);
       for(int i = 0;i<n;i++){
       if(st.count(A[i])>0){
            st.erase(A[i]);
        }else{
            st.insert(A[i]);
        }
        if(st.count(B[i])>0){
            st.erase(B[i]);
        }else{
            st.insert(B[i]);
        }
        int ele = st.size();
        ans[i] = max(0,i+1-ele/2);
       } 
       return ans;
    }
};