class Solution {
public:
    int countCollisions(string d) {
        char curr = ' ';
        int count = 0;
        int ans =0;

        for(int i=0;i<d.size();i++){
            if(d[i]=='R'){
               curr = d[i];
               count++; 
            }else if(d[i]=='S'){
                ans += count;
                count=0;
                curr = d[i];
            }else if(d[i]=='L'){
                if(curr=='S'){
                    ans++;
                }else if(curr=='R'){
                    curr = 'S';
                    ans+= count+1;
                    count=0;
                }
            }
        }
        return ans;
    }
};