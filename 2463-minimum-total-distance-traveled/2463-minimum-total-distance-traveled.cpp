class Solution {
public:
    typedef long long ll;
    ll dp[101][10001];
    ll solve(int r , int f , vector<int>&robot , vector<int>&factory){
        if(r>=robot.size()){return 0;}
        if(f>=factory.size()){return 1e18;}
        if(dp[r][f]!=-1)return dp[r][f];
        ll left = abs((ll)robot[r]-factory[f])+solve(r+1 , f+1 , robot , factory);
        ll right = solve(r , f+1 , robot , factory);
        return dp[r][f] = min(left , right);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory){
      memset(dp , -1 , sizeof(dp));
      sort(robot.begin() , robot.end());
      sort(factory.begin() , factory.end());
      vector<int>position;
      for(auto& it : factory){
        int pos  = it[0];
        int limit = it[1];
        for(int i =0;i<limit;i++){
            position.push_back(pos);
        }
      } 
      return solve(0 , 0 , robot , position);
    }
};