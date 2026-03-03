class Solution {
public:
    char solve(int k){
    if(k==1)return '0';

    int y = std::bit_width((unsigned int)k);
    int last = (1 << (y - 1));

    if(k == last) return '1';   // <-- THIS WAS MISSING

    char ans = solve(2*last - k);
    return ans =='0'?'1':'0';
   }
    
    char findKthBit(int n, int k){
        if(k==1)return '0';
        if(__builtin_popcount(k)==1){return '1';}
        return solve(k);
    }
};