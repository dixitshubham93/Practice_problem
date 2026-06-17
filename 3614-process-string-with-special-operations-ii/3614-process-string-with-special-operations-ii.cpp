class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n);
        long long temp = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (temp > 0) temp--; 
            } else if (s[i] == '%') {
                
            } else if (s[i] == '#') {
                temp *= 2;          
            } else {
                temp++;             
            }
            len[i] = temp;
        }

        if (temp <= k) {
            return '.';
        }

       
        for (int i = n - 1; i >= 0; i--) {
           
            long long prev_len = (i > 0) ? len[i - 1] : 0;

            if (s[i] == '*') {
                
            } else if (s[i] == '%') {
                k = len[i] - 1 - k;
            } else if (s[i] == '#') {
                if (prev_len > 0) {
                    k %= prev_len;
                }
            } else {
                if (k == prev_len) {
                    return s[i];
                }
            }
        }
        
        return '.'; 
    }
};