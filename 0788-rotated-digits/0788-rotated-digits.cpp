class Solution {
public:
    bool solve(int n ,  unordered_set<int>&diff){
        if(n==0){return false;}
        bool ispos = false;
        while(n){
          int temp = n%10;
          n = n/10;
          if(temp==3||temp==7||temp==4){return false;}
          if(diff.count(temp)!=0){ispos = true;
          }
        }
        return ispos;
    }
    int rotatedDigits(int n) {
        unordered_set<int>diff;
        diff.insert(2);
        diff.insert(5);
        diff.insert(6);
        diff.insert(9);
       int count = 0;
       for(int i = 0;i<=n;i++){
        if(solve(i , diff)){
            count++;
        }
       }
    return count;
    }
};