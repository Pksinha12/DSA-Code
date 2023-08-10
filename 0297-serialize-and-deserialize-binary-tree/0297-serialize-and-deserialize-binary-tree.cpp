/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(TreeNode *root, string &s)
    {
        if (root == NULL)
        {
            s.append("*,");
            return;
        }
        s.append(to_string(root->val) + ',');
        preorder(root->left, s);
        preorder(root->right, s);
        return ;
    }
    string serialize(TreeNode *root) 
    {
        string s = "";
        preorder(root, s);
        cout << s;
        return s;
    }
    TreeNode *decode(string &data)
    {
        //edge cases
        if (data.size() == 0) return NULL;
        if (data[0] == '*')
        {
            data = data.substr(2);
            return NULL;
        }
        
        int ind = 0;
        string value = "";
        
        while (data[ind] != ',')
        {
            value += data[ind++];
        }
            
        TreeNode *node = new TreeNode(stoi(value));
        data = data.substr(ind+1);
        node->left = decode(data);
        node->right = decode(data);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if (data.size() <= 2) return NULL;
        return decode(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));