class Solution {
public:
    int digits(int x){
        int count = 0;
        while(x){
            count++;
            x = x/10;
        }
        return count;
    }

    vector<int> sequentialDigits(int low, int high) {
        int start = digits(low);
        int end = digits(high);
        vector<int>ans;
        string temp = "123456789";
        for(int length = start ; length <= end ; length++){
          int left = 0;
           while((left+length-1)<9){          
              int x = stoi(temp.substr(left , length));
              if(x>=low&&x<=high){
                ans.push_back(x);
              }else if(x>high){
                return ans;
              }
              left++;
           }
        }
        return ans;
    }
};