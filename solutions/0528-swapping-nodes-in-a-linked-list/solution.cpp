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
    1. Iterate through the list, get the nodes at index k and n - k + 1.
    2. Swap the values at these nodes.
    */
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode *slow = head, *fast = head, *temp = head;
        int cnt = 0;
        while(temp)
        {
            cnt++;
            if(cnt == k)
                slow = temp;
            temp = temp -> next;
        }
        int end = cnt - k + 1;
        temp = head;
        cnt = 0;
        while(temp)
        {
            cnt++;
            if(cnt == end)
            {
                fast = temp;
                break;
            }
            temp = temp -> next;
        }
        int value = slow -> val;
        slow -> val = fast -> val;
        fast -> val = value;
        return head;
    }
};
