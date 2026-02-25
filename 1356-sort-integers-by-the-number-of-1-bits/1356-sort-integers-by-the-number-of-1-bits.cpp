class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin() , arr.end(),[&](const int a , const int b){
            int x = __builtin_popcount(a);
            int y = __builtin_popcount(b);
            if(x==y){return a<b;}
            else{
                return x<y;
            }
        });
        return arr;
    }
};