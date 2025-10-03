/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    - Using two pointers:
        - slow : which moves only one step.(slow = slow -> next)
        - fast : which moves two steps. (fast = fast -> next -> next)
    - Base Condition:
        - If the list has no nodes, then return false.(No cycle)
        - If the list has only one node, and pos = -1, then return false. (No cycle)
    - Move both the pointer at their respective speed, if fast and slow pointers meet then it's where the cycle exists, return true.
    - How did we know that fast and slow pointers meet?
        - Since the cycle exists, the pointers while moving will get to a same node. 
    */
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL)    return false;
        if(head -> next == NULL)    return false;
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)    return true; 
        }   
        return false;
    }
};
