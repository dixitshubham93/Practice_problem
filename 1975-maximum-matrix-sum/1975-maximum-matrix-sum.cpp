class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long number_of_negative = 0;
        long long summation = 0;
        int mn = INT_MAX;

        int n = matrix.size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]<0){
                    number_of_negative++;
                }
                mn = min(mn , abs(matrix[i][j]));
                summation += 1LL*abs(matrix[i][j]);
            }
        }
        if(number_of_negative%2==0){
            return summation;
        }
        return summation-1LL*2*mn;
    }
};