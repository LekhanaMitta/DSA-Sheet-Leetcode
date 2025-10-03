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
    - Initialise two pointers temp1, temp2 pointing to the heads of list headA, headB respectively.
    - Traverse until temp1 = temp2:
        - Move both the pointers one steps at a time.
        - if any pointers reaches its list's end, then redirect to head of other pointer.
        - This method works because both traverse the same length and then they meet in the way.
    - If both the pointers intersect, the pointers will meet at the intersection node after atmost 2 full traversals, if there is no such intersection node they will meet at the NULL.
    - Return either temp1 or temp2 which gives the intersection node which can also be NULL.
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *temp1 = headA, *temp2 = headB;
        while(temp1 != temp2)
        {
            temp1 = (temp1 != NULL) ? temp1 -> next : headB;
            temp2 = (temp2 != NULL) ? temp2 -> next : headA;
        }    
        return temp1;
    }
};
