class Solution {
public:
    TreeNode *f(int ps, int pe, int is, int ie, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &mp)
    {
        if (is > ie or ps > pe) return NULL;
        TreeNode *root = new TreeNode(preorder[ps]);
        int ind = mp[root->val];
        int len = ind - is;
        root->left = f(ps+1,ps+len, is, ind-1, preorder, inorder, mp);
        root->right = f(ps+len+1, pe, ind+1, ie, preorder, inorder, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        return f(0, n-1, 0, n-1, preorder, inorder, mp);
    }
};