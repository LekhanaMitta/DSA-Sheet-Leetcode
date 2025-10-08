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
    1. Traverse to the last node of list2 so that we can attach it at the bth node of list1.
    2. Traverse the list1 if it's a-1 th node then attach to the head of the list1, and if it's bth node attach the end of list2 to b+1th node.
    3. Return the list1.
    */
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        int cnt = 0;
        ListNode *temp = list1, *temp2 = list2;
        while(temp2 -> next != NULL){
            temp2 = temp2 -> next;
        }
        while(temp)
        {
            if(cnt == a - 1)
            {
                ListNode *temp1 = temp -> next;
                temp -> next = list2;
                temp = temp1;
            }
            if(cnt == b - 1)
            {
                temp2 -> next = temp -> next;
                temp -> next = NULL;
                break;
            }
            cnt++;
            temp = temp -> next;
        }    
        return list1;
    }
};
