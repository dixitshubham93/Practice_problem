class TrieNode{
    public:
    TrieNode* arr[26];
    bool isEnd;

    TrieNode(){
        for(int i = 0;i<26;i++){
            arr[i] = nullptr;
        }
        isEnd = false;
    }
};

class WordDictionary {
public:
    TrieNode* root  = new TrieNode();
    WordDictionary() {
        
    }
    bool dfs(string word , int idx , TrieNode* root){
        if(idx>=word.size()){
            return root->isEnd;
        }

        if(word[idx]!='.'){
            if(root->arr[word[idx]-'a']==nullptr){
                return false;
            }else{
                return dfs(word , idx+1 ,root->arr[word[idx]-'a']);
            }
        }else{
            for(int i = 0;i<26;i++){
                if(root->arr[i]!=nullptr){
                    if(dfs(word , idx+1 ,root->arr[i])){return true;}
                }
            }
        }
        return false;
    }
    void addWord(string word) {
        TrieNode* temp = root;
        for(char it : word){
            if(temp->arr[it-'a']==nullptr){
                temp->arr[it-'a'] = new TrieNode();
            }
            temp = temp->arr[it-'a'];
        }
        temp->isEnd  = true;
        return;
    }
    
    bool search(string word) {
         TrieNode* temp = root;
        return dfs(word , 0 , temp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */