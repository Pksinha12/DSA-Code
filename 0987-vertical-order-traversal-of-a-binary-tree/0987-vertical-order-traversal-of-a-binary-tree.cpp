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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int,multiset<int>>> mp;

        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            TreeNode* node = it.first;
            int vertical = it.second.first;
            int levels = it.second.second;
            
            mp[vertical][levels].insert(node->val);
            
            if (node->left != NULL) q.push({node->left, {vertical-1, levels+1}});
            if (node->right != NULL) q.push({node->right, {vertical+1, levels+1}});
        }
        
        vector<vector<int>> ans;
        for (auto it : mp)
        {
            vector<int> cols;
            for (auto itr : it.second)
            {
                cols.insert(cols.end(), itr.second.begin(), itr.second.end());
            }
            ans.push_back(cols);
        }
        return ans;
    }
};