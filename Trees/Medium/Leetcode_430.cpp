/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* kid(Node* head)
    {
        Node* curr = head, *last = head;
        while(curr)
        {
            Node* next = curr -> next;
            if(!curr -> child)
            {
                last = curr;
                curr = next;
            }
            else
            {
                Node* tail = kid(curr -> child);
                curr -> next = curr -> child;
                curr -> child -> prev = curr;
                curr -> child = NULL;
                if(tail)
                {
                    tail -> next = next;
                    if(next)
                        next -> prev = tail;
                }
                last = tail;
                curr = next;
            }
        }
        return last;
    }
    Node* flatten(Node* head) 
    {
        if(!head)   return NULL;
        kid(head); 
        return head;  
    }
};

/*
- kid function basically returns last element in the dll.
1. Maintain 3 different pointer 
    - curr : for current node. Initialise to head.
    - last : for previous node. Initialise to head.
    - next : for next node. Initialise for curr node.
2. Traverse through the DLL :
    - If there is no child just update the three pointers
        - last :- curr
        - curr :- next
        - next :- curr -> next.
    - If there is a child.
        - curr -> next :- curr -> child.
        - curr -> child -> prev :- curr
        - curr -> child :- NULL
        - Find the end of child by calling the same function:
        - if(tail) 
            - tail -> next :- next
            - if(next)
                - next -> prev :- tail
        - last :- tail
        - curr :- next
    - return last

*/
