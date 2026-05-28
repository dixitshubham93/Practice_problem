#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    // A flat structure to represent a Node using array indices instead of pointers
    struct Node {
        int children[26];
        int bestIndex;
    };

    vector<Node> trie;

    // Helper to create a new node in our flat vector
    int createNode(int defaultIdx) {
        Node newNode;
        for (int i = 0; i < 26; i++) {
            newNode.children[i] = -1; // -1 means no child exists
        }
        newNode.bestIndex = defaultIdx;
        trie.push_back(newNode);
        return trie.size() - 1;
    }

    void insert(const vector<string>& wordsContainer, int wordIdx, int defaultIdx) {
        string word = wordsContainer[wordIdx];
        int currIdx = 0; // The root is always at index 0
        
        for (int i = word.length() - 1; i >= 0; i--) {
            int charIdx = word[i] - 'a';
            
            if (trie[currIdx].children[charIdx] == -1) {
                // Pass the current wordIdx as the initial default best for the new branch
                trie[currIdx].children[charIdx] = createNode(wordIdx);
            }
            
            currIdx = trie[currIdx].children[charIdx];
            
            // Track the best index dynamically at this node
            int oldIdx = trie[currIdx].bestIndex;
            if (word.length() < wordsContainer[oldIdx].length()) {
                trie[currIdx].bestIndex = wordIdx;
            }
        }
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // Clear old data from previous test runs to prevent memory pile-up
        trie.clear(); 

        // 1. Find the global fallback index
        int defaultIdx = 0;
        for (int i = 1; i < wordsContainer.size(); i++) {
            if (wordsContainer[i].length() < wordsContainer[defaultIdx].length()) {
                defaultIdx = i;
            }
        }

        // 2. Initialize the root node at index 0
        createNode(defaultIdx);

        // 3. Build the Trie
        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer, i, defaultIdx);
        }

        // 4. Process Queries
        vector<int> ans;
        ans.reserve(wordsQuery.size()); // Small optimization to prevent vector resizing
        
        for (const string& query : wordsQuery) {
            int currIdx = 0;
            int lastValidIdx = trie[0].bestIndex;
            
            for (int i = query.length() - 1; i >= 0; i--) {
                int charIdx = query[i] - 'a';
                if (trie[currIdx].children[charIdx] == -1) {
                    break; 
                }
                currIdx = trie[currIdx].children[charIdx];
                lastValidIdx = trie[currIdx].bestIndex;
            }
            ans.push_back(lastValidIdx);
        }

        return ans;
    }
};