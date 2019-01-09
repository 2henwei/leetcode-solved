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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;

        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }

    /* Iterative Version */
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;

        stack<TreeNode**> s;
        s.push(new (TreeNode*[2]) {t1, t2});

        while (!s.empty()) {
            TreeNode** t = s.top();
            s.pop();

            if (!t[0] || !t[1]) continue;

            t[0]->val += t[1]->val;

            if (!t[0]->left) {
                t[0]->left = t[1]->left;
            } else {
                s.push(new (TreeNode*[2]) {t[0]->left, t[1]->left});
            }

            if (!t[0]->right) {
                t[0]->right = t[1]->right;
            } else {
                s.push(new (TreeNode*[2]) {t[0]->right, t[1]->right});
            }
        }
        return t1;
    }
};
