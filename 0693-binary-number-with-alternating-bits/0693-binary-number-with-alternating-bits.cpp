class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x = n&1;
        n = n>>1;
        while(n){
            int next = n&1;
            n = n>>1;
            if(next==x){return false;}
            x = next;
        }
        return true;
    }
};