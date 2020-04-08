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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (std::abs(depth(root->right) - depth(root->left)) > 1) {
            return false;
        } 
        return isBalanced(root->left) and isBalanced(root->right);
    }
    
    int depth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return std::max(depth(root->left), depth(root->right))+1; 
    }
    
};