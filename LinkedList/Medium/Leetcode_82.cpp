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
    /*
    1. Use a dummy node (newHead) before the real head → helps handle edge cases easily.
    2. Use two pointers:
        prev → tracks last node confirmed unique.
        curr → scans the list.
    3. If duplicates found, move curr forward until the values change, then link prev->next = curr->next to skip duplicates completely.
    4. If no duplicate, move prev normally. Continue until list end and return newHead->next.
    */
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *newHead = new ListNode(0);
        newHead -> next = head;
        ListNode *curr = head, *prev = newHead;
        while(curr && curr -> next)
        {
            if(curr -> val == curr -> next -> val)
            {
                while(curr -> next && curr -> val == curr -> next -> val)
                    curr = curr -> next;
                prev -> next = curr -> next;
            }
            else
                prev = prev -> next;
            curr = curr -> next;
        }
        return newHead -> next;
    }
};
