class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n-1));
        if(k > total) return "";

        k--; 
        string ans = "";

        for(int pos = 0; pos < n; pos++){

            int block = (pos == 0) ? (1 << (n-1)) : (1 << (n-pos-1));

            int ch = k / block;
            k %= block;

            for(int i = 0; i < 3; i++){
                if(!ans.empty() && ans.back() - 'a' == i) continue;

                if(ch == 0){
                    ans.push_back('a' + i);
                    break;
                }
                ch--;
            }
        }

        return ans;
    }
};