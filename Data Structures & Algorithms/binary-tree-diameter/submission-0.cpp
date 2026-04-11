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
    int result = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxLength(root);
        return result;
        
    }

    int maxLength(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = maxLength(root->left);
        int right = maxLength(root->right);

        result = max(left + right, result);
        return 1 + max(left, right) ;
    }
};
