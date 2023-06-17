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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if (root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        vector<vector<int>> ans;
        while(!q.empty())
        {
            int sz = q.size();
            flag = !flag;
            vector<int> levels;
            for (int i = 0; i < sz; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                levels.push_back(node->val);
            }
            if (flag) ans.push_back(levels);
                else
                {
                    reverse(levels.begin(), levels.end());
                    ans.push_back(levels);
                }
                
        }
        return ans;
    }
};