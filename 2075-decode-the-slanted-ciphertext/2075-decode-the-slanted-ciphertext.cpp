class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int col = n/rows;
        string s ="";       
       for(int i = 0;i<col;i++){        
           int r = 0;
           int c = i;
           while(r<rows&&c<col){
            s.push_back(encodedText[r*col +c]);
            r++;
            c++;
           }
        }
        while(!s.empty()&&s.back()==' '){s.pop_back();}

        return s;
    }
};