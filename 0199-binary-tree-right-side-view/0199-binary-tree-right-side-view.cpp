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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)return {};
        vector<int>ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root , 0});
        ans.push_back(root->val);
        while(!q.empty()){
            int size = q.size();
        for(int i=0;i<size;i++){
           auto it = q.front();
           q.pop();
           TreeNode* node = it.first;
           int col = it.second;
           if(node->left!=nullptr){
            q.push({node->left , col-1});
           }
           if(node->right!=nullptr){
            q.push({node->right , col+1});
           }
        }
        if(!q.empty()){
          ans.push_back(q.back().first->val);
            }

        }

    return ans;
    }
};