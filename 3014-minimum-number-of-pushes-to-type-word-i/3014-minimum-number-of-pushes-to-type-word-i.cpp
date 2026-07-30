class Solution {
public:
    int minimumPushes(string word) {
        int n  = word.size()/8;
        int r  = word.size()%8;
        return n*(8 + 4*(n-1)) + r*(n+1);
    }
};