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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (root == NULL) return {};
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> levels;
            for (int i = 0; i < sz; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                int val = node->val;
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                levels.push_back(val);
            }
            ans.push_back(levels);   
        }
        return ans;
    }
};