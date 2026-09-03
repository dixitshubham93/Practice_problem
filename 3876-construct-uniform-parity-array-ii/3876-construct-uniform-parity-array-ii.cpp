class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int se  = INT_MAX;
        int so = INT_MAX;
        for(int i = 0;i<nums1.size();i++){
           if(nums1[i]%2==0){
           se = min(se , nums1[i]);}
           else{
           so = min(so , nums1[i]);}
        }

        if(se == INT_MAX || so == INT_MAX ) return true;
        return so<se;
    }
};