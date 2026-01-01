class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0 ;
        int n = nums.size();
        for(int i = 0;i<32;i++){
            int count = 0;
          for(int j = 0 ;j<n;j++){
           count += nums[j]&1;
          nums[j] =  nums[j]>>1;
          }
          if(count%3!=0){
            if(i == 31 ){
                ans += -pow(2,i);
            }else{
            ans += pow(2,i);
            }
          } 
        }  
      return ans;
    }
};