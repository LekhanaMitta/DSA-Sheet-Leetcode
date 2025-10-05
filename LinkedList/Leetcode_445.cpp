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
    - Traverse both linked lists and push their node values into two separate stacks. This reverses the order logically so we can start adding from the least significant digit (the  end of each list).
    - Create a pointer res = nullptr to store the resulting list and an integer carry = 0.
    - While either stack still has elements or there is a carry:
        - Pop the top element from each stack if available.
        - Add them along with the carry to get sum.
        - Update carry = sum / 10 and the current digit as sum % 10.
    - For each computed digit, create a new node and insert it at the head of the result list. This keeps the number in the correct forward order.
    - After processing all digits and carry, return the head of the result list, which now represents the sum of the two input numbers.
    */
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
