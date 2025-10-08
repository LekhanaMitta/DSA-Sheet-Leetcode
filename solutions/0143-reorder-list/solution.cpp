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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL, *temp = head;
        while(temp)
        {
            ListNode *next = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) 
    {
        ListNode *slow = head, *fast = head;
        while(fast -> next)
        {
            if(fast -> next -> next == NULL)
                break;
            slow = slow -> next;
            fast = fast -> next -> next;
        }    
        ListNode *temp = slow -> next;
        slow -> next = NULL;
        ListNode *head2 = reverse(temp);
        ListNode *head1 = head -> next, *newHead = head;
        int cnt = 1;
        while(head1 || head2)
        {
            if(cnt % 2 == 1 || head1 == NULL)
            {
                newHead -> next = head2;
                head2 = head2 -> next;
                cnt++;
            }
            else if(cnt % 2 == 0 || head2 == NULL)
            {
                newHead -> next = head1;
                head1 = head1 -> next;
                cnt++;
            }
            newHead = newHead -> next;
        }
        // while(head1)
        // {
        //     newHead -> next = head1;
        //     head1 = head1 -> next;
        //     newHead = newHead -> next;
        // }
        // while(head2)
        // {
        //     newHead -> next = head2;
        //     head2 = head2 -> next;
        //     newHead = newHead -> next;
        // }
        // return head;
    }
};
