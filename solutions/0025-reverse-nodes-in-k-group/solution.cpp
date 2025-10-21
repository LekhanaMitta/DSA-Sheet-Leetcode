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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(k == 1)  return head;
        ListNode *temp = head;
        int cnt = 1;
        while(temp && cnt < k)
        {
            temp = temp -> next;
            cnt++;
        }
        if(cnt < k || temp == NULL) return head;
        ListNode *curr = head, *prev = NULL, *next = NULL;
        cnt = 0;
        while(curr && cnt < k)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        head -> next = reverseKGroup(curr, k);
        return prev;
    }
};
