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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        // Write down parent vector using level order traversals
        queue<TreeNode*> q;
        q.push(root);
        map<TreeNode*, TreeNode*> parent;
        map<TreeNode*, int> visited; 
        parent[root] = NULL;
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) 
            {
                q.push(node->left);
                parent[node->left] = node;
                //cout << parent[node->left]->val;
            }
            if (node->right)
            {
                q.push(node->right);
                parent[node->right] = node;
                //cout << parent[node->left]->val;
            }
        }
        q.push(target);
        visited[target] = 1;
        while (!q.empty() and k)
        {
            k--;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                visited[node] = 1;
                if (visited[node->left] != 1 and node->left) q.push(node->left);
                if (visited[node->right] != 1 and node->right) q.push(node->right);
                if (visited[parent[node]] != 1 and parent[node]) q.push(parent[node]);
            }
            
        }
        vector<int> ans;
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};