class Solution {
public:
    int closestToZero(const vector<int>& nums) {
    int closest = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (abs(nums[i]) < abs(closest) ||
           (abs(nums[i]) == abs(closest) && nums[i] > closest)) {
            closest = nums[i];
        }
    }
    return closest;
}

    int dp[500][500];
    int Getmax(vector<int>& nums1, vector<int>& nums2 , int idx1 , int idx2){

        if(idx1==-1||idx2==-1){
            return 0;
        }
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        //cases

        int val1 = nums1[idx1]*nums2[idx2]+Getmax(nums1 , nums2 , idx1-1 , idx2-1);
        int val2 = Getmax(nums1 , nums2 , idx1 , idx2-1);
        int val3 = Getmax(nums1 , nums2 , idx1-1 , idx2);
        int val4 = Getmax(nums1 , nums2 , idx1-1 , idx2-1);
       
       return dp[idx1][idx2]=max(val1 , max(val2 , max(val3 , val4)));
    }
     
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

     memset(dp, -1, sizeof(dp));

      int n = nums1.size();
      int m = nums2.size();
      int ans =  Getmax(nums1 , nums2 , n-1 , m-1);
      
      int min1 = closestToZero(nums1);
      int min2 = closestToZero(nums2);
      

      if(ans==0)return (min1)*(min2);
      return ans;

    }
};