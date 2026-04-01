class Solution {
public:
    int solve(vector<int>&histo){
        int n = histo.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        for(int i = 0;i<n;i++){
            while(!st.empty()&&histo[st.top()]>histo[i])st.pop();
            int temp = st.empty()?i+1:i-st.top();
            left[i] = temp;
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        for(int i = n-1;i>=0;i--){
            while(!st.empty()&&histo[st.top()]>=histo[i])st.pop();
            int temp = st.empty()?n-i:st.top()-i;
            right[i] = temp;
            st.push(i);
        }
        int ans = 0;
        for(int i =0;i<n;i++){
            ans += left[i]*histo[i]*right[i];
        }   
        return ans;
    }
    int numSubmat(vector<vector<int>>& mat) {
       int n = mat.size();
       int m = mat[0].size();
       vector<int>histo(m,0);
       int ans = 0;
       for(int i = 0;i<n;i++){
         for(int j = 0;j<m;j++){
            if(mat[i][j]==1){
               histo[j]++; 
            }else{
                histo[j]=0;
            }
         }
        ans += solve(histo);
       }
       return ans;
    }
};