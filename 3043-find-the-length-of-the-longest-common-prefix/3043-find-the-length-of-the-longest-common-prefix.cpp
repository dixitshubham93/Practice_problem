class Solution {
public:
    void solve(unordered_set<int>&st , int num){
        while(num){
            st.insert(num);
            num = num/10;
        }
    }
    int siz(int n){
        int count = 0;
        while(n){
            count++;
            n = n/10;
        }
        return count;
    }
    int get(unordered_set<int>&st , int num){
        while(num){
            if(st.count(num)){return siz(num);}
            num = num/10;
        }
        return 0;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        unordered_set<int>st;
        for(int i = 0;i<n;i++){
           solve(st , arr1[i]);
        }
        int ans = 0;
        for(int i = 0;i<arr2.size();i++){
            ans = max(ans , get(st , arr2[i]));
        }
        return ans;
    }
};