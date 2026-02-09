// Last updated: 2/9/2026, 1:27:40 PM
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