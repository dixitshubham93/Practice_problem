class Solution {
public:
    int maxDistance(vector<int>& colors) {
        pair<int , int>p1 = {-1,-1};
        pair<int , int>p2 = {-1,-1};
        int ans = 0;
        for(int i = 0;i<colors.size();i++){

            if(colors[i]==p1.second||colors[i]==p2.second){
                if(colors[i]==p1.second&&p2.first!=-1){
                    ans = max(ans , i - p2.first);
                }else if(p1.first!=-1){
                    ans = max(ans , i - p1.first);
                }
                continue;
            }else{
                if(p1.first!=-1){
                ans = max(ans , i-p1.first);
                }
                if(p2.first!=-1){
                ans = max(ans , i-p2.first);
                }
            }
            if(p1.first==-1){
                p1.first = i;
                p1.second = colors[i];
            }else if(p2.first==-1){
                p2.first = i;
                p2.second = colors[i];
            }
        }
     return ans;
    }
};