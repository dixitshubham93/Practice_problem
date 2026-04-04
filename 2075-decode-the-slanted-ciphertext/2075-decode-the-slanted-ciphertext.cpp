class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int col = n/rows;
        vector<vector<char>>vec(rows ,vector<char>(col,' '));
        string s ="";
        for(int i = 0;i<n;i++){
            vec[i/col][i%col]=encodedText[i];
        }
        for(int i = 0;i<col;i++){        
           int r = 0;
           int c = i;
           while(r<rows&&c<col){
            s.push_back(vec[r][c]);
            r++;
            c++;
           }
        }
        while(!s.empty()&&s.back()==' '){s.pop_back();}

        return s;
    }
};