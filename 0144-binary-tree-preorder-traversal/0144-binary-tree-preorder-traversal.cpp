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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if (root == NULL) return {};
        
        vector<int> ans;
        stack<TreeNode*> st;
        
        st.push(root);
        
        while (!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            if (node->right != NULL) st.push(node->right); // remember first right should be inserted and then left should be insereted;
            if (node->left != NULL) st.push(node->left);
        }
        return ans;
    }
};