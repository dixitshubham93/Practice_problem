class Solution {
public:

    bool rotateString(string s, string goal){
        if(s.size()!=goal.size())return false;
        string com = s+s;
        int n = com.size();
        return com.find(goal)<n;
    }
};