class Solution {
public:
    bool hasAllCodes(string s, int k){
    
    int n = s.size();
    if(n-k+1<pow(2,k)){return false;}
    unordered_set<int>seen;
    int mask = pow(2,k)-1;
    int temp = 0;
    for(int i = 0;i<k;i++){
         temp = temp<<1;
         temp = temp | (s[i] - '0');

    }  
    seen.insert(temp);
 
    for(int i = k;i<n;i++){
         temp = temp<<1;
         temp = temp | (s[i] - '0');
         temp = temp&mask;
         seen.insert(temp);
    }
         return seen.size()==pow(2,k);
}

};