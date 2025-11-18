class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
       bool c = true;
        for(int i=0;i<bits.size();i++){
          if(bits[i]==1){
            i++;
            c= false;
          }else{
             c= true;
          }
        }
        return c;
    } 
};