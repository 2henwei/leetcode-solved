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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> record;
        _inorderTraversal(root, record);
        return record;
    }

    void _inorderTraversal(TreeNode* root, vector<int>& record) {
        if (!root) return;
        _inorderTraversal(root->left, record);
        record.push_back(root->val);
        _inorderTraversal(root->right, record);
    }

	/* Iterative version */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> record;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        if (!curr) return {};

        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            record.push_back(curr->val);
            curr = curr->right;
        }
        return record;
    }
};
