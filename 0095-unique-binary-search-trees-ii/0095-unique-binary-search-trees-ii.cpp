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
    vector<TreeNode*> solve(int start, int end, map<pair<int, int>, vector<TreeNode*>>& dp) {
        if (start > end) {
            return {NULL};
        }
        if (start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        if (dp.find({start, end}) != dp.end()) return dp[{start, end}];
        vector<TreeNode*> ans;
        for (int k = start; k <= end; k++)
        {
            vector<TreeNode*> left_BSTs = solve(start, k-1, dp);
            vector<TreeNode*> right_BSTs = solve(k+1, end, dp);
            for (TreeNode* l : left_BSTs) {
                for (TreeNode* r : right_BSTs) {
                    TreeNode* root = new TreeNode(k);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return dp[{start, end}] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> dp;
        return solve(1, n, dp);
    }
};