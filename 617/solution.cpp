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

        stack<pair<TreeNode*, TreeNode*>> s;
        s.push(make_pair(t1, t2));

        while (!s.empty()) {
            pair<TreeNode*, TreeNode*> t = s.top();
            s.pop();

            if (!t.first || !t.second) continue;

            t.first->val += t.second->val;

            if (!t.first->left) {
                t.first->left = t.second->left;
            } else {
                s.push(make_pair(t.first->left, t.second->left));
            }

            if (!t.first->right) {
                t.first->right = t.second->right;
            } else {
                s.push(make_pair(t.first->right, t.second->right));
            }
        }
        return t1;
    }
};
