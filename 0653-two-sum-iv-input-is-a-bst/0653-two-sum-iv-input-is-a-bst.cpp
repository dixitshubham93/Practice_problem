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

class BSTIterator1 {
public:
    stack<TreeNode*> st;

    BSTIterator1(TreeNode* root) {
        pushLeft(root);
    }

    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushLeft(node->right);
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

class BSTIterator2 {
public:
    stack<TreeNode*> st;

    BSTIterator2(TreeNode* root) {
        pushRight(root);
    }

    void pushRight(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->right;
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushRight(node->left);
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator1 l(root);
        BSTIterator2 r(root);

        int i = l.next();
        int j = r.next();

        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) {
                if (l.hasNext()) i = l.next();
                else break;
            } else {
                if (r.hasNext()) j = r.next();
                else break;
            }
        }
        return false;
    }
};
