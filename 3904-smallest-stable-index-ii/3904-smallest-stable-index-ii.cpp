class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int>mx(n , 0);
    vector<int>mn(n , 0);

    int temp = INT_MIN;
    for(int i = 0;i<n;i++){
        temp = max(temp , nums[i]);
        mx[i] = temp;
    }
    temp = INT_MAX;
    for(int i = n-1;i>=0;i--){
        temp = min(temp , nums[i]);
        mn[i] = temp;
    }
    for(int i = 0;i<n;i++){
        if((mx[i]-mn[i])<=k){
            return i;
        }
    }
     return -1;
    }
};