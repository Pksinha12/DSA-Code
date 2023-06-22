/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    void mark_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp, TreeNode* target)
    {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* current = q.front();
            q.pop();
            if (current->left) 
            {
                mp[current->left] = current;
                q.push(current->left);
            }
            if (current->right) 
            {
                mp[current->right] = current;
                q.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*, TreeNode*> mp;
        mark_parents(root, mp, target);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target] = true;
        
        int curr_level = 0;
        
        while (!q.empty())
        {
            int size = q.size();
            if (curr_level++ == k) break;
            
            for (int i = 0; i < size; i++)
            {
                TreeNode* current =  q.front();
                q.pop();
                if (current->left and !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right and !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if (mp[current] and !visited[mp[current]])
                {
                    q.push(mp[current]);
                    visited[mp[current]] = true;
                }
            }
        }
        vector<int> result;
        while (!q.empty())
        {
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};