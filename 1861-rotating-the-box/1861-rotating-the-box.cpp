class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid){

        int n = boxGrid.size();
        int m = boxGrid[0].size();
        
        for(int i = 0;i<n;i++){
            int pre = m;
            for(int j = m-1;j>=0;j--){
               if(boxGrid[i][j]=='*'){
                pre = m;
                continue;}
               if(boxGrid[i][j]=='.'){   
                if(pre==m){pre=j;}        
               } 
               if(boxGrid[i][j]=='#'){
                if(pre!=m&&boxGrid[i][pre]=='.'){
                    boxGrid[i][j] = '.';
                    boxGrid[i][pre] = '#';
                    pre--;
                }
               }
            }
        }
        cout<<m<<endl;
        vector<vector<char>>ans(m);
         for(int i = 0;i<m;i++){
            for(int j = n-1;j>=0;j--){
               ans[i].push_back(boxGrid[j][i]);
               } 
            }
        return ans;
    }
};