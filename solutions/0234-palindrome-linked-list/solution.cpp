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
    bool isPalindrome(ListNode* head) 
    {
        if(head -> next == NULL)    return head;
        ListNode *slow = head, *fast = head;
        stack<int> st;
        while(fast != NULL)
        {
            if(fast -> next == NULL)
            {
                slow = slow -> next;
                break;
            }
            st.push(slow -> val);
            // cout << slow -> val << " ";
            slow = slow -> next;
            if(fast -> next -> next == NULL)    break;
            fast = fast -> next -> next;
        } 
        cout << slow -> val ;   
        while(slow != NULL && !st.empty())
        {
            int temp = st.top();
            st.pop();
            // cout << temp << " ";
            if(slow != NULL && temp != slow -> val) return false;
            slow = slow -> next;
        }
        return true;
    }
};
