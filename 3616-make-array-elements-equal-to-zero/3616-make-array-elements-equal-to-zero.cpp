class Solution {
public:
    
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();

        vector<int>pre = nums;
        vector<int>pos = nums;
        
        for(int i=1;i<n;i++){
            pre[i] += pre[i-1];
        }
        for(int i=n-2;i>=0;i--){
            pos[i] += pos[i+1];
        }
         int count=0;
         
        for(int i=1;i<n-1;i++){
         if(nums[i]==0){
            if(pre[i-1]==pos[i+1]){count+=2;}
            else if(abs(pre[i-1]-pos[i+1])==1){
                count++;
            }
         }
        }
         if(1<n&&nums[0]==0){
            if(pos[1]==0){count+=2;}
            else if(pos[1]==1){count++;}
         }
         if(n-2>=0&&nums[n-1]==0){
            if(pre[n-2]==0){count+=2;}
            else if(pre[n-2]==1){count++;}
         }
         if(n==1&&nums[0]==0)return 2;

     return count;
    }
};