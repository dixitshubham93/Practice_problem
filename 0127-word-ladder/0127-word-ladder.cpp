#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        int level = 1; // beginWord itself counts as level 1

        while (!q.empty()) {
            int size = q.size(); // process all words of current level
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                if (word == endWord) return level;

                for (int j = 0; j < word.size(); j++) {
                    char original = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        if (st.find(word) != st.end()) {
                            q.push(word);
                            st.erase(word); // mark visited
                        }
                    }
                    word[j] = original; // restore original character
                }
            }
            level++; // increase level after finishing current layer
        }

        return 0; // no transformation found
    }
};
