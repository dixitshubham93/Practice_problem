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
    int MOD = 1e9 + 7;
    long long ans = 0;

    int summation(TreeNode* root){
        if(root==nullptr)return 0;

        int l = summation(root->left);
        int r = summation(root->right);

        return root->val +l+r;
    }
    long long solve(TreeNode* root , long long sum){
        if(root==nullptr)return 0;

        long long l = 1LL*solve(root->left,sum);
        long long r = 1LL*solve(root->right,sum);

        long long val1 =  1LL*root->val +l+r;
        long long val2 = sum - val1;
        ans = max(ans , val1*val2);

        return val1;
    }


    int maxProduct(TreeNode* root) {
        int sum = summation(root);
        cout<<sum<<endl;
        ans = 0;
        solve(root , 1LL*sum);
        return ans%MOD;
    }
};