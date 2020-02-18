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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int depthRight = minDepth(root->right);
        int depthLeft = minDepth(root->left);
        // int depth
        if (depthLeft == 0 || depthRight == 0) {
            return std::max(depthRight, depthLeft)+1;
        }
        return std::min(depthRight, depthLeft)+1;
    }
};