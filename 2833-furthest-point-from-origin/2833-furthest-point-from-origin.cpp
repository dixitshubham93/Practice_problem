class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int pos = 0;
        int temp = 0;
        for(char it : moves){
            if(it=='L'){
                pos--;
            }else if(it=='R'){
                pos++;
            }else if(it =='_'){
               temp++;
            }
        }
        return abs(pos)+temp;
    }
};