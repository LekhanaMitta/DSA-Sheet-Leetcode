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

/*
Approach:
- Initialize a dummy node head and a pointer ans pointing to it. Also initialize a variable carry = 0 to store any carry generated during addition.
- Traverse both linked lists l1 and l2 simultaneously until both become null and there is no carry left.
For each step:
    - Take the current value of l1 if it exists, otherwise 0.
    - Take the current value of l2 if it exists, otherwise 0.
    - Compute the sum of the two values and the carry.The new digit will be sum % 10, and the new carry will be sum / 10.
    - Create a new node with the digit value sum % 10 and attach it to the next of the current pointer ans.
    - Move ans to this new node to continue building the result list.
    - Move l1 and l2 forward to their next nodes if they are not null, and continue until the loop ends.
- Finally, return head->next, which represents the head of the resulting linked list.
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* ans = head;
        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            int a = (l1 != NULL) ? l1 -> val : 0;
            int b = (l2 != NULL) ? l2 -> val : 0;
            int sum = a + b + carry;
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            ans -> next = temp;
            ans = ans -> next;
            l1 = (l1 != NULL) ? l1 -> next : NULL;
            l2 = (l2 != NULL) ? l2 -> next : NULL;
        }
        return head -> next;
    }
};
