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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }

    /* Iterative Version */
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int max_depth = 0;
        stack<pair<int, TreeNode *>> s;
        s.push(pair<int, TreeNode *>(1, root));

        while (!s.empty()) {
            pair<int, TreeNode *> curr = s.top();
            s.pop();

            int depth = curr.first;
            TreeNode *node = curr.second;

            if (!node) continue;
            if (depth > max_depth) max_depth = depth;

            s.push(pair<int, TreeNode *>(depth + 1, node->left));
            s.push(pair<int, TreeNode *>(depth + 1, node->right));
        }
        return max_depth;
    }
};
