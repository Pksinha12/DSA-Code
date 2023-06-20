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
    bool isCheck(TreeNode* Left, TreeNode* Right)
    {
        if (Left == NULL || Right == NULL) return Left == Right;
        
            return (Left->val==Right->val)
            and isCheck(Left->right, Right->left)
            and isCheck(Left->left, Right->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isCheck(root->left, root->right);
    }
};