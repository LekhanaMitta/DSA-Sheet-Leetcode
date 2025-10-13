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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head || !head -> next || !head -> next -> next)
            return head;
        ListNode *dummy1 = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        ListNode *temp = head, *temp1 = dummy1, *temp2 = dummy2;
        int cnt = 1;
        while(temp)
        {
            if(cnt % 2 == 1)
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
            cnt++;
        }
        temp1 -> next = dummy2 -> next;
        temp2 -> next = NULL;
        return dummy1 -> next;
    }
};
