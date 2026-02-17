class Solution {
public:
    int getBitCount(int n ){
        int count = 0;
        while(n){
            if(n&1){count++;}
            n = n>>1;
        }
        return count;
    }
    vector<string> readBinaryWatch(int turnedOn){
      if(turnedOn>8){return {};}
       vector<string>ans;
       for(int h = 0;h<=11; h++){
        for(int m = 0;m<=59;m++){

            int bits = getBitCount(h) + getBitCount(m);
            if(bits==turnedOn){
                if(m<=9){
                   string s  = to_string(h) + ":"+"0" + to_string(m);
                   ans.push_back(s);
                }else{
                     string s  = to_string(h) + ":"+  to_string(m);
                   ans.push_back(s);
                }
            }
        }
       }
       return ans;
    }
};