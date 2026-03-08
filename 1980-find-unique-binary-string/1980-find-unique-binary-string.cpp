class Solution {
public:
    int solve(string s){
        int ans = 0;
        for(int i  = 0;i<s.size();i++){
            ans = ans*2 + (s[i]-'0');
        }
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums){
        vector<int>temp;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            temp.push_back(solve(nums[i]));
            cout<<temp[i]<<" ";
        }
        sort(temp.begin() , temp.end());
        int s = n;
        for(int i = 0;i<n;i++){
            if(i!=temp[i]){
                s = i;
                break;
            }
        }
        string ans = "";
        while(s){
            string a = to_string(s&1);
            ans = a + ans;
            s = s>>1;
        }
        while(ans.size()!=n){
          ans = "0" + ans;
        }
        return ans;
    }

};