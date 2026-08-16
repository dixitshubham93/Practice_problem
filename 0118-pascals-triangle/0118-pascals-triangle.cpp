class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        for(int i = 1;i<=numRows;i++){
           if(i==1){
            ans[i-1].push_back(1);
           }else{
              int temp = 0;
              while(temp<i){
                if(temp==0||temp==(i-1)){
                    ans[i-1].push_back(1);
                }else{
                    ans[i-1].push_back(ans[i-2][temp-1]+ans[i-2][temp]);
                }
                temp++;
              }
           }
        }
        return ans;
    }
};