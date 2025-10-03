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
    - Keep track of prev, and curr pointer for every node. Because, here we sever the link between current node to next node, and join that link from current node to previous node.
    - prev -> curr -> next ------------> prev <- curr <- next
    - Use curr to track current pointer and initialise to head, and prev node as NULL.
    - Traverse until curr reaches end:
        - Hold the next pointer(temp = curr -> next).
        - Sever the curr -> next connection, and attach it to prev.(curr -> next = prev) which does curr -> next ------> prev <- curr.
        - then move both the prev and curr to their respective next nodes.
    - As the curr reaches end, prev is made as the end node and return prev.
    step - 1: prev --> NULL      curr -> next -> next2 -> NULL
    Step - 2: prev <- curr      next(temp) -> next2 -> NULL
    Step - 3: prev1 <- prev(before curr)    curr(before next) -> next2 -> NULL
    Step - 4: prev1 <- prev(before curr) <- curr(before next)  next2 -> NULL
    Step - 5: prev2 <- prev1 <- prev(before curr) <- curr(before next) <- NULL
    Step - 6: prev3 <- prev2 <- prev1 <- prev(before curr) <- curr(before NULL)
    return prev, since it became head for reversed list.
    */
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* curr = head, *prev = NULL;
        while(curr != NULL)
        {
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }   
        return prev;
    }
};
