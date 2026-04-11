class Solution {
public:
    void dfs(string beginWord, vector<string>& seq,
             unordered_map<string, int>& level, vector<vector<string>>& ans,
             string b) {
        if (beginWord == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        string word = beginWord;
        int steps = level[word];
        for (int i = 0; i < word.size(); i++) {
            char actual = word[i];
            for (char it = 'a'; it <= 'z'; it++) {
                word[i] = it;
                if (level[word] == steps - 1) {
                    seq.push_back(word);
                    dfs(word, seq, level, ans, b);
                    seq.pop_back();
                }
            }
            word[i] = actual;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_map<string, int> WordLevel;
        unordered_set<string> List(wordList.begin(), wordList.end());
        WordLevel[beginWord] = 1;

        queue<string> q;
        q.push(beginWord);

        if (List.count(beginWord)) {
            List.erase(beginWord);
        }
        vector<vector<string>> ans;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = WordLevel[word];

            if (word == endWord) {
                vector<string> seq;
                seq.push_back(endWord);
                dfs(endWord, seq, WordLevel, ans, beginWord);
                return ans;
            }
            for (int i = 0; i < word.size(); i++) {
                char actual = word[i];
                for (char it = 'a'; it <= 'z'; it++) {
                    word[i] = it;
                    if (List.count(word)) {
                        WordLevel[word] = steps + 1;
                        List.erase(word);
                        q.push(word);
                    }
                }
                word[i] = actual;
            }
        }

        return ans;
    }
};