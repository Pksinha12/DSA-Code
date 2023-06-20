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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root == NULL or root == p or root == q) return root;
        
        TreeNode* Left = lowestCommonAncestor(root->left, p, q);
        TreeNode* Right = lowestCommonAncestor(root->right, p, q);
        
        if (Left == NULL) return Right;
        else if (Right == NULL) return Left;
        else return root;
    }
};