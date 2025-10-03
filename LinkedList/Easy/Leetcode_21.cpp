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
    - It's a basic two pointer approach. Use pointer temp1 from the head of list1, and temp2 as the head of list2.
    - Here I'm doing inplace merging which basically is I'm not using any extra space or O(1), and merging the lists.
    - Base Case:
        - If any of the lists are empty return the other list.
    1. Create a dummy node which will act as the head for the merged list.
    2. Link the node from either list1 or list2 based on comparing the current nodes' values.
    3. While, traversing both the lists until one becomes NULL:
        - If temp1 -> val <= temp2 -> val, so the temp1 node has to be appended to the new list, then move the temp1 to next pointer.
        - Else, temp2 node has to ne appended, and temp2 is moved to next pointer.
    4. If any of the list still has not reached the end then append the rest of list to new list.
    5. Since, we placed a dummy node infront of new merged list, return the next pointer of it's head.
    */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *temp1 = list1, *temp2 = list2;
        if(temp1 == NULL)   return temp2;
        if(temp2 == NULL)   return temp1;
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1 -> val <= temp2 -> val)
            {
                temp -> next = temp1;
                temp1 = temp1 -> next;
            }
            else
            {
                temp -> next = temp2;
                temp2 = temp2 -> next;
            }
            temp = temp -> next;
        }   
        if(temp1 != NULL)
            temp -> next = temp1;
        if(temp2 != NULL)
            temp -> next = temp2;
        return head -> next;
    }
};
