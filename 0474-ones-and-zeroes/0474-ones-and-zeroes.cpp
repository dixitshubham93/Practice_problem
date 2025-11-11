class Solution {
public:
    vector<vector<vector<int>>>dp;
     pair<int , int>counter(string& s){
        int one = 0;
        int zero = 0;

        for(char it : s){
            if(it=='1'){
                one++;
            }else{
                zero++;
            }
        }
      return {zero , one};
    }
    int solve(vector<string>& strs,int index , int m, int n){
        if(index==strs.size()){
            if(m>=0&&n>=0){
               return 0;
            }
            return -1e4;
            }
             if(m<0||n<0)return -1e4;
             if(dp[index][m][n]!=-1)return dp[index][m][n];
             int ans = 0;
           
            int l = solve(strs ,  index+1 , m , n );
            pair<int , int> it = counter(strs[index]);
            int r =  1+solve(strs , index+1 , m-it.first, n-it.second);  
       return dp[index][m][n]=max(l , r);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.assign(strs.size() , vector<vector<int>>(m+1 , vector<int>(n+1 , -1)));
        return solve(strs , 0 , m , n);
    }
};