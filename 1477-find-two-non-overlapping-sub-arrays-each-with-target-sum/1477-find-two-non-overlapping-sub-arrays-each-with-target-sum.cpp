class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int>minLength(n , INT_MAX);
        int ans = INT_MAX;
        int minsub = INT_MAX;

        int i = 0;
        int sum = 0;

        for(int j = 0;j<n;j++){
            sum += arr[j];
            while(j>i&&target<sum){
                sum -= arr[i];
                i++;
            }
            if(sum==target){
                if(i>0&&minLength[i-1]!=INT_MAX){
                   ans = min(ans ,  minLength[i-1]+j-i+1);
                }
                minsub = min(minsub , j-i+1);
            }
            minLength[j] = minsub;
        }
        return ans==INT_MAX?-1:ans;
    }
};