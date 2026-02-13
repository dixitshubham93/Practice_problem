class Solution {
public:
    int case2(string s , char ch1 , char ch2){
        unordered_map<int , int>mp;
        int count1 = 0;
        int count2 = 0;
        int ans = INT_MIN;
        mp[0] = -1;
        for(int i = 0;i<s.size();i++){
            char it = s[i];
            if(ch1!=it&&ch2!=it){
                mp.clear();
                count1 = 0;
                count2 = 0;
                mp[0] = i;
                continue;
            }
            if(it==ch1){count1++;}
            if(it==ch2){count2++;}
            
            if(mp.count(count1-count2)){
                ans = max(ans ,i- mp[count1-count2]);
            }else{
              mp[count1 - count2] = i;
            }
        }

        return ans;
    }
    int longestBalanced(string s) {
        unordered_map<string, int> mp;
        mp["0#0"] = -1;

        int ca = 0, cb = 0, cc = 0;
        int ans = 1;

        int case1 = 1;
        for(int i = 1;i<s.size();i++){
           if(s[i] == s[i-1]){
            case1++;
           }else{
             case1 = 1; 
           }
             ans = max(ans , case1);
        }
        //case 2
        ans = max(ans , case2(s , 'a' , 'b'));
        ans = max(ans , case2(s , 'a' , 'c'));
        ans = max(ans , case2(s , 'c' , 'b'));


        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a') ca++;
            if(s[i] == 'b') cb++;
            if(s[i] == 'c') cc++;

            string key = to_string(cb - ca) + "#" + to_string(cc - ca);
              
            if(mp.count(key)){
                ans = max(ans, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }

        return ans;
    }
};
