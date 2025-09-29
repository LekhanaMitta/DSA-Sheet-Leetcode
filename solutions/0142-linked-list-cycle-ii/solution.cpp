/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL) return NULL;
        if(head -> next == NULL)    return NULL;
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)    break;
        }    
        if(!fast || !fast -> next)  return NULL;
        slow = head;
        while(slow != fast)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        if(slow == fast)    return slow;
        return NULL;
    }
};
