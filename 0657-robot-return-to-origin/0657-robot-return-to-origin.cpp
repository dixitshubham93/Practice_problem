class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, pair<int , int>>mp;
        mp['U'] = {-1 , 0};
        mp['D'] = {1 , 0};
        mp['R'] = {0 , 1};
        mp['L'] = {0 , -1};
       

        pair<int , int>coordinate={0 , 0};

        int n = moves.size();

        for(int i = 0;i<n;i++){
           coordinate.first += mp[moves[i]].first;
           coordinate.second += mp[moves[i]].second;
        }
        return coordinate.first==0&&coordinate.second==0;
    }
};