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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(head != NULL)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL and fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) 
    {
        if (head == NULL or head->next == NULL) return true;
        ListNode* mid = findMid(head);
        mid->next = reverse(mid->next);
        ListNode* start = head;
        mid = mid->next;
        while (mid != NULL)
        {
            if (start->val != mid->val) return false;
            start = start->next;
            mid = mid->next;
        }
        return true;
    }
};