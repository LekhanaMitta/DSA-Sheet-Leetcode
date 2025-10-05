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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> st1, st2;
        ListNode *temp1 = l1, *temp2 = l2;    
        while(temp1 != NULL)
        {
            st1.push(temp1 -> val);
            temp1 = temp1 -> next;
        }
        while(temp2 != NULL)
        {
            st2.push(temp2 -> val);
            temp2 = temp2 -> next;
        }
        // ListNode *head = new ListNode(0);
        ListNode *res = NULL;
        int carry = 0;
        while(!st1.empty() || !st2.empty() || carry)
        {
            int sum = carry;
            if(!st1.empty())
            {
                sum += st1.top();
                st1.pop();
            }
            if(!st2.empty())
            {
                sum += st2.top();
                st2.pop();
            }
            carry = sum/10;
            ListNode *temp = new ListNode(sum%10);
            temp -> next = res;
            res = temp;
        }
        return res;
    }
};
