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
    1. Create two dummy nodes where we can make odd list and even list.
    2. Traverse through the head, for every odd node append it to dummy1, for even node append it to dummy2, for that use cnt variable and increment it for every node we moved.
    3. Once the head is traversed, append end of dummy1 to 2nd node of dummy2(because 1st node of dummy2 is dummy), and end of dummy2 as end.
    4. Return dummy1 -> next.
    */
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
