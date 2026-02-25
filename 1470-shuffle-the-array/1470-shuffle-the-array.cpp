class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n){
        vector<int>arr(2*n);
        int p1 = 0;
        int p2 = n;
        for(int i = 0;i<2*n;i++){
           if(i%2==0){
            arr[i] = nums[p1];
            p1++;
           }else{
            arr[i] = nums[p2];
            p2++;
           }
        }
        return arr;
    }
};