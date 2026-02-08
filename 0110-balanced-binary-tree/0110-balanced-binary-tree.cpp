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
    int Balanced(TreeNode* root) {
       if(root==nullptr){return 0;} 
       int l = 1 + Balanced(root->left);
       int r = 1 + Balanced(root->right);
       if(l>=1e4||r>=1e4){return 1e4;}
       return abs(l-r)>1?1e4:max(l,r);
    }
    bool isBalanced(TreeNode* root) {
    
       return Balanced(root)>=1e4?false:true;
    }
};