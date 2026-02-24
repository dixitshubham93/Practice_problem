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
    int sum;
    int st(string s){
        int count = 0;
        int n =  s.size();
        for(int i =n-1;i>=0;i--){
            count += (s[i]-'0')*pow(2,n-1-i);
         }
         return count;
    }
    void solve(string temp , TreeNode* root){

        if(root->left==nullptr&&root->right==nullptr)
        {   
            temp.push_back(root->val+'0');
            sum += st(temp);
            temp.pop_back();
            return ;
        }
       
        if(root->left!=nullptr){
        solve(temp + to_string(root->val) , root->left);
        }
        if(root->right!=nullptr){
        solve(temp + to_string(root->val) , root->right);
        }

        return ;
    }
    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        solve("" , root);
        return sum;
    }
};