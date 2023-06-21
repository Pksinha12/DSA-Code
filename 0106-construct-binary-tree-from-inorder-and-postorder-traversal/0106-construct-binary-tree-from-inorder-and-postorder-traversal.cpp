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
    TreeNode* helper(int is, int ie, int ps, int pe, unordered_map<int, int>& mp,vector<int>& inorder, vector<int>& postorder)
    {
        if (is > ie or ps > pe) return NULL;
        
        TreeNode* root = new TreeNode(postorder[pe]);
        int rootIdx = mp[postorder[pe]];
        int numsLeft = rootIdx-is;
        
        root->left = helper(is, rootIdx-1, ps, ps+numsLeft-1, mp, inorder, postorder);
        root->right = helper(rootIdx+1, ie, ps+numsLeft, pe-1, mp, inorder, postorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if (inorder.size() != postorder.size()) return NULL;
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        int is = 0, ie = inorder.size()-1;
        int ps = 0, pe = postorder.size()-1;
        TreeNode* root = helper(is, ie, ps, pe, mp, inorder, postorder);
        return root;
    }
};