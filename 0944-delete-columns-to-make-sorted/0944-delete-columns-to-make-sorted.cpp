class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int c = strs[0].size();

        int n = strs.size();
        int count = 0;

        for(int i = 0;i<c;i++){
            for(int j = 1;j<n;j++){
                if(strs[j][i]<strs[j-1][i]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};