class Fancy {
public:
    long long MOD = 1e9+7;
    pair<long long , long long>am;
    vector<long long>arr;
    Fancy() {
        am.first =  0;
        am.second = 1;
    }
    long long getPow(long long x , long long p){
         if(p==1){return x;}
         long long result = getPow(x , p/2);
         result  = (result%MOD*result%MOD)%MOD;
         if(p%2==1){
            result  = (result*x%MOD)%MOD;
         }
         return result;
    }
    void append(int val) {
        if(am.first==0&&am.second==1){
            arr.push_back(val);
            return ;
        }
        long long temp = (val-am.first+MOD)%MOD*getPow(am.second , MOD-2)%MOD;
        arr.push_back(temp);
        return ;
    }
    
    void addAll(int inc) {
        am.first+=inc;
    }
    
    void multAll(int m) {
        am.second = (am.second%MOD*m%MOD)%MOD;
        am.first  = (am.first%MOD*m%MOD)%MOD;
    }
    
    int getIndex(int idx) {
        if(arr.size()<=idx){return -1;}
         if(am.first==0&&am.second==1){
            return arr[idx]%MOD;
        }
        return (arr[idx]*am.second%MOD + am.first%MOD)%MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */