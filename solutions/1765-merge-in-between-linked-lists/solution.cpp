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
