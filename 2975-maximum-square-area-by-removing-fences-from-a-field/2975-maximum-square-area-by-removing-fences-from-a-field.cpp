class Solution {
public:

    int MOD = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v){
        long long ans = 0;
        if(h.front()!=1){h.insert(h.begin() , 1);}
        if(h.back()!=m){h.push_back(m);}
        if(v.front()!=1){v.insert(v.begin() , 1);}
        if(v.back()!=n){v.push_back(n);}

        unordered_set<int>s;
        for(int i = 0;i<h.size()-1 ; i++){
            for(int j = i+1;j<h.size();j++){
            s.insert(abs(h[i] - h[j]));
        }}

        for(int i = 0;i<v.size()-1; i++){
            for(int j = i+1;j<v.size();j++){
           if(s.count(abs(v[i] - v[j]))==1){
              ans = max(ans , 1LL*abs(v[i] - v[j]));
           }
        }}
        ans = ans%MOD;   
        return ans==0?-1:(ans*ans)%MOD;
    }
};