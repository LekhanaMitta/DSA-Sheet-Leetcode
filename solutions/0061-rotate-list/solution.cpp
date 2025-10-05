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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        int n = 0;
        ListNode *temp = head;
        while(temp != NULL)
        {
            n++;
            temp = temp -> next;
        } 
        if(n == 0)
            return head;
        // cout << n << " ";
        k = (k%n);
        if(k == 0)
            return head;
        temp = head;
        int cnt = 1;
        ListNode *slow = head, *fast = head;
        while(fast!= NULL && cnt <= k)
        {
            fast = fast -> next;
            cnt++;
        }   
        while(fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        temp = slow -> next;
        slow -> next = NULL;
        fast -> next = head;
        return temp;
    }
};
