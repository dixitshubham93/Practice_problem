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
     TreeNode* ans;
    void solve(TreeNode* root1,TreeNode* root2, TreeNode* p, TreeNode* q)
    {
        if(root1==nullptr||root2==nullptr)return ;
        if(root1==root2){ans = root1;}
        if(root1!=root2){return;}
        if(root1->val>p->val&&root2->val>q->val){
            solve(root1->left,root2->left,p,q);
        }
        if(root1->val<p->val&&root2->val<q->val){
            solve(root1->right,root2->right,p,q);
        }
        return ;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==q)return p;
       ans = nullptr;
       solve(root , root , p,q);
       return ans; 
    }
};