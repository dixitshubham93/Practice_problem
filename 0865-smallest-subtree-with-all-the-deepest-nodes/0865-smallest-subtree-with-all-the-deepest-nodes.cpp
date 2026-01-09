class Solution {
public:
    // build parent map + compute max depth
    int find_depth(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (root == nullptr) return -1;

        if (root->left) mp[root->left] = root;
        if (root->right) mp[root->right] = root;

        int l = 1 + find_depth(root->left, mp);
        int r = 1 + find_depth(root->right, mp);

        return max(l, r);
    }


    void add_Node(int depth, TreeNode* root, queue<TreeNode*>& q) {
        if (root == nullptr) return;

        if (depth == 0) {
            q.push(root);
            return;
        }

        add_Node(depth - 1, root->left, q);
        add_Node(depth - 1, root->right, q);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == nullptr) return nullptr;

        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;

        int depth = find_depth(root, parent);
        add_Node(depth, root, q);

       
        while (q.size() > 1) {
            int sz = q.size();
            unordered_set<TreeNode*> seen;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (parent.count(node))
                    seen.insert(parent[node]);
            }

            for (auto p : seen)
                q.push(p);
        }

        return q.front();
    }
};
