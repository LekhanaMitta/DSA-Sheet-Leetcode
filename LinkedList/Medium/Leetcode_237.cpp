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
    1. We are not deleting the node, we are just referencing the node that has to be removed to it's next node.
    2. So, the node that needed to be removed will become as it's next node, while it's next node will be made NULL.
    */
    void deleteNode(ListNode* node) 
    {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;    
    }
};
