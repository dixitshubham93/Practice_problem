/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int preindex =0;
    TreeNode* make_tree(vector<int>& preorder , unordered_map<int ,int>&mp , int s , int e){
      if(s>e)return nullptr;
      int rootVal = preorder[preindex++];
      TreeNode* root = new TreeNode(rootVal);
      
      int index = mp[rootVal];
      if(index>=s&&index<=e){
          root->left = make_tree(preorder , mp , s , index-1);
          root->right = make_tree(preorder , mp ,  index+1 ,e);
      }else{
          root->left = make_tree(preorder , mp , s , -1);
          root->right = make_tree(preorder , mp , 0 , e);

      }
     return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int ,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return make_tree( preorder ,mp ,0 ,inorder.size()-1);
    }
};