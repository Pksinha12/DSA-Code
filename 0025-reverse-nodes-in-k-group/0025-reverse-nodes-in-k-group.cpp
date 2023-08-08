/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* temp = head;
        //finding length of list;
        int len = 0;
        while(temp!= NULL)
        {
            len++;
            temp = temp->next;
        }
        //No of times reverse is required;
        int t = len/k;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        ListNode *nex = dummy;
        ListNode *prev = dummy;
        while (t--)
        {
            cur = prev->next;
            nex = cur->next;
            //below is genereal reversing operations
            for (int i = 1; i < k; i++)
            {
                cur->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = cur->next;
            }
            prev = cur;
        }
        return dummy->next;
    }
};