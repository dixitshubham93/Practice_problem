class Solution {
public:
    void findlps(vector<int>&lps,string needle){
     int suf = 1;
     int pre = 0;
     while(suf<needle.size()){
        if(needle[suf]==needle[pre]){
            lps[suf] = pre+1;
            suf++;
            pre++;
        }else{
            if(pre==0){
                lps[suf] = 0;
                suf++;
            }else{
                pre = lps[pre-1];
            }
        }
     }
    }
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

       vector<int>lps(m , 0);
       findlps(lps , needle);

       int first = 0;
       int second = 0;
       while(first<n&&second<m){
        if(haystack[first]==needle[second]){
            first++;
            second++;
        }else{
            if(second==0){first++;}
            else{
               second = lps[second-1];
            }
        }
       }
       if(second==m)return first-second;
       return -1;
    }
};