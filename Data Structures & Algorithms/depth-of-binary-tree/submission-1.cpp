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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        stack<pair<int, TreeNode*>> q;
        q.push({1, root});

        int result = 1;

        while (!q.empty()) {
            TreeNode* node = q.top().second;
            int level = q.top().first;

            q.pop();

            result = max(result, level);

            if (node->left) {
                q.push({level + 1, node->left});
            }
            if (node->right) {
                q.push({level + 1, node->right});
            }
        }

        return result;
    }
};
