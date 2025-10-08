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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *temp = head;
        ListNode *newHead1 = new ListNode(0);
        ListNode *newHead2 = new ListNode(0);
        ListNode *temp1 = newHead1, *temp2 = newHead2;
        while(temp)
        {
            if(temp -> val < x)
            {
                temp1 -> next = temp;
                temp1 = temp1 -> next;
            }
            else
            {
                temp2 -> next = temp;
                temp2 = temp2 -> next;
            }
            temp = temp -> next;
        }
        temp2 -> next = NULL;
        temp1 -> next = newHead2 -> next;
        newHead1 = newHead1 -> next;
        return newHead1;
    }
};
