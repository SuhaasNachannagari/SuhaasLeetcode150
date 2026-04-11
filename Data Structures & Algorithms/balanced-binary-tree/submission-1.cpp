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
    bool isBalanced(TreeNode* root) {
        return subTreeBalanced(root).second;
    }

    pair<int, bool> subTreeBalanced (TreeNode* root) {
        if (!root) {
            return {0, true};
        }

        // Get information from children (balance/height)

        auto left = subTreeBalanced(root->left);
        auto right = subTreeBalanced(root->right);

        // Calculate whether this node is balanced based on the children
        if (!left.second || !right.second || abs(left.first - right.first) > 1) {
            return {max(left.first, right.first) + 1, false,};
        }

        return {max(left.first, right.first) + 1, true};

    }

};
