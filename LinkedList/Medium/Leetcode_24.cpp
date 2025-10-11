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
    1. While swapping 1st and 2nd node we make 2nd node as 1st and 1st node as 2nd.
    2. But for dealing with the next pointers for these nodes, 2nd node's next will be pointing to the 1st node. How about nex tpointer of 1st node?
    3. It points to the 2nd nodes of next set of nodes. Basically, all the next pair of nodes must be swapped before the first pair of nodes.
    4. We use recursion to do that. 
    */
    ListNode* swapPairs(ListNode* head) 
    {
        if(!head || !head -> next)  return head;
        ListNode *temp = head -> next;
        head -> next = swapPairs(head -> next -> next);
        temp -> next = head;
        return temp; 
    }
};
