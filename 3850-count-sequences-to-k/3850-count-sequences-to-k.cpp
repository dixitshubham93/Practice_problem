class Solution {
public:
        unordered_map <string, int> dp;
    int solve(vector<int>& nums, long long k, int i, int c2, int c3, int c5){
        if(i >= nums.size()){
            if(c2 >= 0 && c3 >= 0 && c5 >= 0 && (k == pow(2, c2) * pow(3, c3) * pow(5, c5))){  
                return 1;
            }
            return 0;
        }
        string key = to_string(i) + "#" +  to_string(c2) + "#" + to_string(c3) + "#" + to_string(c5);
        if(dp.find(key) != dp.end()) return dp[key];

        int tc2 = 0;
        int tc3 = 0;
        int tc5 = 0;
                switch(nums[i]){
            case 1:
                break;

            case 2:
                tc2 = 1;
                break;

            case 3:
                tc3 = 1;
                break;

            case 4:
                tc2 = 2;
                break;

            case 5:
                tc5 = 1;
                break;

            case 6:
                tc2 = 1;
                tc3 = 1;
                break;
            }

        int ans = solve(nums, k, i+1, c2, c3, c5);             
        ans += solve(nums, k, i+1, c2+tc2, c3 + tc3, c5 + tc5); 
        ans += solve(nums, k, i+1, c2-tc2, c3 - tc3, c5 - tc5); 
        
        return  dp[key] = ans;
    }
    
    int countSequences(vector<int>& nums, long long k) {    
        return solve(nums, k, 0, 0, 0, 0);
    }
};