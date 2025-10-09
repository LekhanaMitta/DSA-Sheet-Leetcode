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
    1. Find the element before the middle node, i.e., mid - 1.
    2. We generally use two pointers slow (moves 1-step) and fast (moves 2 - steps) to get to the mid of the linked list.
    3. But if we want to stop at mid -1 node, then use fast -> next -> next -> next (because for list with odd no. of nodes with next fast's movement i.e., two step at a time, slow reaches the mid, but we need only mid -1 node. So we stop here), fast -> next -> next (for even no. of nodes this makes sure we reach length/2 node which basically itself mid -1 node).
    4. We traverse slow pointer only until we reach mid -1 node.
    5. Make mid -1 next to the mid +1 .
    6. Return head.
    */
    ListNode* deleteMiddle(ListNode* head) 
    {
        if(head -> next == NULL)    return NULL;
        ListNode *slow = head, *fast = head;
        while(fast -> next && fast -> next -> next && fast -> next -> next -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *mid = slow -> next;
        slow -> next = mid -> next;
        return head;
    }
};
