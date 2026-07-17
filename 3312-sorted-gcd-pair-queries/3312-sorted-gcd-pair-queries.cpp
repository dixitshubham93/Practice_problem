class Solution {
public:

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin() , nums.end());
        vector<long long>arr(mx+1);
        //1
        for(int i = 0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        //2
        for(int i = 1;i<=mx;i++){
            for(int j = 2*i;j<=mx;j+=i){
               arr[i] += arr[j];
            }
        }
        //3
        for(int i = 1;i<=mx;i++){         
        arr[i] = (arr[i]*(arr[i]-1))/2;         
        }
        //4
        for(int i = mx;i>0;i--){
            for(int j = 2*i;j<=mx;j+=i){
                arr[i] -= arr[j];
            }
        }
        //5
        for(int i = 1;i<=mx;i++){
            arr[i] += arr[i-1];
        }

        vector<int>ans;
        //6
        for(long long it:queries){
          int gc = lower_bound(arr.begin() , arr.end() , it+1)-arr.begin();
          ans.push_back(gc);
        }
        return ans;
    }
};