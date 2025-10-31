class Solution {
public:
    bool isInRange(TreeNode* root, long long minrange, long long maxrange) {
        if (root == nullptr) return true;
        if (!(minrange < root->val && root->val < maxrange)) return false;
        return isInRange(root->left, minrange, root->val) && 
               isInRange(root->right, root->val, maxrange);
    }

    bool isValidBST(TreeNode* root) {
        return isInRange(root, LLONG_MIN, LLONG_MAX);
    }
};
