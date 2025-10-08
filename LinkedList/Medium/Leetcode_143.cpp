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
    1. Finding the middle element. If even no. of nodes then take second middle element.
    2. Reverse the second half of the list.
    3. Merge the first half and second half one after the other.
    - I considered a cnt for which cnt is odd I added second half, else first half.
    - Follow this until both the lists are empty.
    */
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
    }
};
