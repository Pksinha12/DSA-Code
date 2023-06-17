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
private:
    int helper(TreeNode* root, int& diam)
    {
        if (root == NULL) return 0;
        
        int lh = helper(root->left, diam);
        int rh = helper(root->right, diam);
        diam = max(diam, lh+rh);
        
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int diameter = 0;
        helper(root,diameter);
        return diameter;
    }
};