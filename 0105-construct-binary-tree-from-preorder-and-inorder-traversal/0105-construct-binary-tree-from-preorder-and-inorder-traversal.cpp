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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        int inStart = 0;
        int inEnd = inorder.size()-1;
        int preStart = 0;
        int preEnd = preorder.size()-1;
        TreeNode* root = helper(inStart, inEnd, preStart, preEnd,mp, preorder, inorder);
        return root;
    }
    TreeNode* helper(int inStart, int inEnd, int preStart, int preEnd,unordered_map<int, int>& mp, vector<int>& preorder, vector<int>& inorder)
    {
        if (inStart > inEnd || preStart > preEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int rootIdx = mp[root->val]; // giving index of root in the inorder.
        int numsLeft = rootIdx - inStart; // numbers of element to the left of root 
        
        root->left = helper(inStart, rootIdx-1, preStart+1, preStart+numsLeft, mp, preorder, inorder);
        root->right = helper(rootIdx+1, inEnd, preStart+numsLeft+1, preEnd,  mp, preorder, inorder);
        return root;
    }
};