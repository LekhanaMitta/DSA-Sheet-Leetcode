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
        return head-> next;
    }
};
