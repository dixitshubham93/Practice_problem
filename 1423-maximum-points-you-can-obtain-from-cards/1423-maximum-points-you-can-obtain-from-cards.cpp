class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k){

        int n  = cardPoints.size();
        int sum = accumulate(cardPoints.begin() , cardPoints.end() , 0);
        if(n<=k){return sum;}
        int len = n - k;
        int temp = 0;
        int remove = INT_MAX;
        int left = 0;
        for(int i = 0;i<cardPoints.size();i++){
            temp += cardPoints[i];
            if(i-left+1==len){
               remove = min(remove , temp);
               temp  -= cardPoints[left];
               left++;
            }
        }
      return sum - remove;
    }
};