class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
     sort(nums.begin() , nums.end());
     int e1 = 0;
     int e2 = 0;
     int e3 = 0;
     int ans = 1e6;
     int n = nums.size();
     int p2 = n-1;
     for(int i= 0;i<nums.size();i++){
        int p1 = i+1;
        int p2 = n-1;
        while(p1<p2){
            int sum = nums[i]+nums[p1]+nums[p2];
            if(abs(ans-target)>abs(target-sum)){ans = sum;}
            if(sum>target){
                p2--;
            }else{
                p1++;
            }
        }
     }
      return ans;
    }
};