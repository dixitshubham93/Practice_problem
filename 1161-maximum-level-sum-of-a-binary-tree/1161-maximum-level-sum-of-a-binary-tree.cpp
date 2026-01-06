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
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*>q;
        int ans =INT_MIN;
        
        if(root==nullptr)return 0;
        q.push(root);
        int level = 0;
        int ans_level = 0;
        while(!q.empty()){
             int size = q.size();
             level++;
             int temp = 0;
             for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                temp += node->val;
                if(node->right!=nullptr){
                   q.push(node->right);
                }
                if(node->left!=nullptr){
                   q.push(node->left);
                }
                q.pop();
             }
             if(ans<temp){
                ans = temp;
                ans_level = level;
             }
        }
      return ans_level;
    }
};