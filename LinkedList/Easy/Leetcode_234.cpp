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
    Base Case: If there is only one node, return the head by default.
    Approach:
    - My intuition is to push the first half of elements into a stack, and pop each element in the stack while comparing it with next half elements of list.
    - To push the first half of elements I followed the two pointer slow and fast pointer approach, and push value of slow pointer into stack.
    - For the middle element(in odd no. of nodes) don't push just skip to next pointer.
    - Now as I empty the stack compare the top value with curr node's value. If not same then return false, palindrome did not occur.
    - Once, the stack is empty return true, because elements are same. 
    */
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
            slow = slow -> next;
            if(fast -> next -> next == NULL)    break;
            fast = fast -> next -> next;
        } 
        cout << slow -> val ;   
        while(slow != NULL && !st.empty())
        {
            int temp = st.top();
            st.pop();
            if(slow != NULL && temp != slow -> val) return false;
            slow = slow -> next;
        }
        return true;
    }
};
