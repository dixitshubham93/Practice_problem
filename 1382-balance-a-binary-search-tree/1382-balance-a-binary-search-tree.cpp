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

    vector<int>inorder;
    TreeNode* makebinary(int s , int e){
        if(s>e){
           return nullptr;
        }
        int mid = (s+e)/2;
        TreeNode* parent =  new TreeNode(inorder[mid]);
        parent->left = makebinary(s , mid-1);
        parent->right = makebinary(mid+1 , e);
        return parent;
    }
    void  BST(TreeNode* root) {
        if(root==nullptr){
         return;
        } 
        BST(root->left);
        inorder.push_back(root->val);
        BST(root->right); 
     return ;         
    }
   TreeNode* balanceBST(TreeNode* root){
    BST(root);
    int n = inorder.size();
    return makebinary(0 , n-1);
    }

};