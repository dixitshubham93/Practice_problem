class TrieNode{
public:
 vector<TrieNode*>children{2 , nullptr};
 bool isEnd = false;
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(int num){
        TrieNode* node = root;
        for(int i = 31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->children[bit]==nullptr){
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
        node->isEnd = true;
    }
    int getMax(int num){
         TrieNode* node = root;
         int ans = 0;
        for(int i = 31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->children[1-bit]!=nullptr){
                ans = ans|(1<<i);
                node = node->children[1-bit];
            }else{           
                node = node->children[bit];
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        insert(nums[0]);
        int ans = 0;
        for(int i = 1;i<nums.size();i++){
        ans = max(ans , getMax(nums[i]));
        insert(nums[i]);
        }
        return ans;
    }
};