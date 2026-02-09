// Last updated: 2/9/2026, 1:26:48 PM
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
    ListNode* reverseEvenLengthGroups(ListNode* head) 
    {
        if(head -> next == NULL || head -> next -> next == NULL)  return head;
        int group = 1;
        ListNode *temp = head;
        while(temp && temp -> next)
        {
            int cnt = 0;
            group++;
            ListNode *temp1 = temp -> next;
            while(temp1 && cnt < group)
            {
                temp1 = temp1 -> next;
                cnt++;
            }
            if(cnt % 2 == 0)
            {
                ListNode *curr = temp -> next, *prev = NULL, *next = NULL;
                for(int i = 0;i < cnt;i++)
                {
                    next = curr -> next;
                    curr -> next = prev;
                    prev = curr;
                    curr = next;
                }
                ListNode *temp2 = temp -> next;
                temp2 -> next = curr;
                temp -> next = prev;
                temp = temp2;
            }
            else
            {
                for(int i=0;i<cnt;i++)
                    temp = temp -> next;
            }
        }
        return head;
    }
};