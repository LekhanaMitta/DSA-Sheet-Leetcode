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
    /* I guess for most of the linked list based question the intuition is to use two pointer, the slow and the fast pointer.
    - Base case: If the list contains only one node, the return the list
    - Initialize slow and fast pointer to head.
    - Here, slow pointers moves by one step, while the fast pointers moves by two steps at a time.
    - This way works because, as the fast pointer reaches end which is x distance, slow pointer reaches x/2 distance which basically is the middle of the linked list.
    - If the no. of nodes is odd, this thing works. But when no. of nodes is even return the slow -> next i.e., the second middle element.
    - How to know if no. of nodes is odd or even. If curr -> next == NULL (which is last node) then the no. of nodes is odd (fast jumps from 1, 3, 5, ... 2x + 1, NULL). If curr -> next -> next == NULL (which is last but one node) then the no. of nodes is even.
    */
    ListNode* middleNode(ListNode* head) 
    {
        if(head -> next == NULL)    return head;
        ListNode *slow = head, *fast = head;
        while(fast != NULL)
        {
            if(fast -> next == NULL)    return slow;
            if(fast -> next -> next == NULL)    return slow -> next;
            slow = slow -> next;
            fast = fast -> next -> next;
        }    
        return slow;
    }
};
