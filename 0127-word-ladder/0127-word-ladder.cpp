class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        if (beginWord == endWord) {
            return 1;
        }
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.count(beginWord)) {
            st.erase(beginWord);
        }
        if (!st.count(endWord)) {return 0;}
        int dis = 1;
        while (!q.empty()){
            int size = q.size();
            dis++;
            for (int j = 0; j < size; j++) {
                string str = q.front();
                q.pop();
                int n = str.size();
                for (int i = 0; i < n; i++) {
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        char temp = str[i];
                        str[i] = ch;
                        if (str == endWord) {
                            return dis;
                        }
                        if (st.count(str)) {
                            st.erase(str);
                            q.push(str);
                        }
                        str[i] = temp;
                    }
                }

            }
        }
        return 0;
    }
};