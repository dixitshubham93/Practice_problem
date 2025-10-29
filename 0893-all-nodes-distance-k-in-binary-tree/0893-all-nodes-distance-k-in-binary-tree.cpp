/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,unordered_map< TreeNode*,TreeNode*>&mp){
         if(root==nullptr)return ;
         if(root->left!=nullptr){
          mp[root->left] = root;
         dfs(root->left , mp);
         }
         if(root->right!=nullptr){
          mp[root->right] = root;
         dfs(root->right , mp);
         }
         return ;
    }
    void traversal(TreeNode* root,unordered_map< TreeNode*,TreeNode*>&mp , int dis ,vector<int>&ans){
    if(root==nullptr){
        return ;
    }
     if(dis==0){
            ans.push_back(root->val);
     }
     TreeNode* parent = nullptr;
       if(mp.find(root)!=mp.end()){
       parent = mp[root];
       }
       mp.erase(root);
      
       if(parent!=nullptr&&mp.find(parent)!=mp.end()){
        traversal(parent , mp , dis-1 , ans);
       }
       if(root->left!=nullptr&&mp.find(root->left)!=mp.end()){
        traversal(root->left , mp , dis-1 , ans);
       }
       if(root->right!=nullptr&&mp.find(root->right)!=mp.end()){
        traversal(root->right , mp , dis-1 , ans);
       }
       return ;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map< TreeNode* ,  TreeNode*>mp;
        mp[root] = nullptr;
        vector<int>ans;
        dfs(root , mp);
        traversal(target , mp , k , ans);
        return ans;
    }
};