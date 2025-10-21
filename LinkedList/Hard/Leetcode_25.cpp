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
    Approach :
    1. Check for the base case where k = 1 return head,if no. of nodes is less than k then we need not reverse the list.
    2. Reverse the first k nodes and then link it to next k reversed nodes.
    */
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
