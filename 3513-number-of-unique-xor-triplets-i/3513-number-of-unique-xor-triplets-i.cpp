class Solution {
public:
    int countBit(int n){
        int count = 0;
        while(n){
            n = n>>1;
            count++;
        }
        return count;
    }
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int bit = countBit(n);
        int addOn = 2*(1<<(bit-1));

        if(n<=2){
        return n;
        }
        
        return addOn;
    }
};