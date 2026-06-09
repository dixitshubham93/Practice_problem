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
    vector<TreeNode*> solve(int l , int r ){
      if(r<l)return {nullptr};

      vector<TreeNode*>ans;

      for(int i = l;i<=r;i++)
      {
        vector<TreeNode*>leftTree = solve(l , i-1);
        vector<TreeNode*>RightTree = solve(i+1 , r);
        for(auto&l:leftTree){
            for(auto& r:RightTree){
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
      }
      return ans;
    }
    vector<TreeNode*> generateTrees(int n) {  
       return  solve(1 , n); 
    }
};