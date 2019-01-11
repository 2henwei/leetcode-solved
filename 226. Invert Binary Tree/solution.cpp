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
    /* Recursive Version */
	TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;

        TreeNode *left  = root->left;
        TreeNode *right = root->right;

        root->left = invertTree(right);
        root->right = invertTree(left);

        return root;
    }

	/* Iterative Version */
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;

        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();

            if (!node) continue;

            TreeNode *left  = node->left;
            TreeNode *right = node->right;

            node->left = right;
            node->right = left;

            s.push(right);
            s.push(left);
        }
        return root;
    }
};
