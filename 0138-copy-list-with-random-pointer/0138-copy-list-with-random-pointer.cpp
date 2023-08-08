/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node* cur = head;
        unordered_map<Node*, Node*> mp;
        while (cur != NULL)
        {
            Node* node = new Node(cur->val);
            mp[cur] = node;
            cur = cur->next;
        }
        cur = head;
        while (cur != NULL)
        {
            Node* copyNode = mp[cur];
            copyNode->random = mp[cur->random];
            copyNode->next = mp[cur->next];
            cur = cur->next;
        }
        return mp[head];
    }
};