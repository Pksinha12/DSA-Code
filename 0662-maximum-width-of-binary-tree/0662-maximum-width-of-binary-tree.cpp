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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long unsigned>> q;
        q.push({root, 0});
        long long unsigned ans = 0;
        while (!q.empty())
        {
            long long unsigned sz = q.size();
            long long unsigned first, last;
            for (long long unsigned i = 0; i < sz; i++)
            {
                auto it = q.front();
                q.pop();

                TreeNode* node = it.first;
                long long unsigned curr = it.second;

                if (i == 0) first = curr;
                if (i == sz-1) last = curr;

                if (node->left != NULL) q.push({node->left, curr*2+1});
                if (node->right != NULL) q.push({node->right, curr*2+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};