
class TrieNode{
    public:
    unordered_map< char,TrieNode*> arr;
    bool isEnd;
    TrieNode(){
        for(int i = 0;i<26;i++){
            arr[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* main = new TrieNode();
    
    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode* root = main;
        for(int i = 0;i<word.size();i++){
            if(root->arr[word[i]]==nullptr){
                root->arr[word[i]] = new TrieNode();
            }
            root = root->arr[word[i]];
        }
        root->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* root = main;
        for(int i = 0;i<word.size();i++){
            if(root->arr[word[i]]==nullptr){
                return false;
            }
            root = root->arr[word[i]];
        }
    return root->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* root = main;
        for(int i = 0;i<prefix.size();i++){
            if(root->arr[prefix[i]]==nullptr){
                return false;
            }
            root = root->arr[prefix[i]];
        }
    return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */