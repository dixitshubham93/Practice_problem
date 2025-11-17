class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        int count = 0;
        int n = nums.size();
        bool d = false;

        for(int i =0;i<n;i++){
           
            if(d){
               if(nums[i]==0){
               count++;
            }else if(count<k){
                return false;
            }else{
                count=0;
            }
            }
             if(nums[i]==1){

                d = true;
            }
            
        }

        return true;
    }
};