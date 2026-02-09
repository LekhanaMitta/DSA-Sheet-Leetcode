// Last updated: 2/9/2026, 1:26:42 PM
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
    ListNode* removeNodes(ListNode* head) 
    {
        if(!head)   return head;
        stack<int> st;
        ListNode *dummy = NULL;
        ListNode *temp = head;
        while(temp)
        {
            while(!st.empty() && st.top() < temp -> val)
            {
                st.pop();
            }
            st.push(temp -> val);
            temp = temp -> next;
        }
        while(!st.empty())
        {
            dummy = new ListNode(st.top(), dummy);
            st.pop();
        }
        return dummy;
    }
};