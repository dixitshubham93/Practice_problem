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
    void dfs(int row , int col , TreeNode* root , map<int ,map<int,multiset<int>>>&mp){
        mp[col][row].insert(root->val);
        if(root->left!=nullptr){
            dfs(row+1 , col-1 , root->left , mp);
        }
         if(root->right!=nullptr){
            dfs(row+1 , col+1 , root->right , mp);
        }
      return ;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int , multiset<int>>>mp;
        if(root==nullptr)return {};
        dfs(0 , 0 , root  , mp);
        vector<vector<int>>ans;
        for(auto& it : mp){
        vector<int>temp;
         for(auto& it2 : it.second){
           temp.insert(temp.end() , it2.second.begin() , it2.second.end());
         }
         ans.push_back(temp);
    }
    return ans;
    }
};