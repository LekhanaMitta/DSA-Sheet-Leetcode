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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        // int cnt = 1;
        // ListNode* temp = head;
        // while(temp -> next != NULL)
        // {
        //     cnt++;
        //     temp = temp -> next;
        // }
        // cout << cnt << " ";
        // int x = cnt - n;
        // cout << x << " ";
        // if(x == 0)
        //     return head -> next;
        // cnt = 1;
        // temp = head;
        // while(cnt < x && temp -> next != NULL)
        // {
        //     cnt++;
        //     temp = temp -> next;
        // }    
        // ListNode* temp1 = temp -> next;
        // if(temp -> next -> next == NULL)
        // {
        //     temp -> next = NULL;
        // }
        // else
        // {
        //     temp ->next = temp1 -> next;
        //     temp1 -> next = NULL;
        // }
        // // delete(temp1);
        // // free(temp1);
        // return head;

        ListNode *start = new ListNode(0);
        start -> next = head;
        ListNode *slow = start, *fast = start;
        int cnt = 0;
        while(cnt <= n)
        {
            cnt++;
            fast = fast -> next;
        }
        while(fast != NULL)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        if(slow -> next != NULL)
        {
            ListNode *temp = slow -> next;
            slow -> next = temp -> next;
            temp -> next = NULL;
        }
        return start -> next;

    }
};
