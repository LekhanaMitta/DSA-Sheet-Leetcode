// Last updated: 2/9/2026, 1:27:17 PM
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
    vector<int> nextLargerNodes(ListNode* head) 
    {
        stack<int> st;
        ListNode *temp = head;
        int cnt = 0;
        while(temp)
        {
            temp = temp -> next;
            cnt++;
        }
        temp = head;
        vector<int> ans(cnt, 0);
        for(int i = 0;i<cnt && temp;i++)
        {
            ans[i] = temp -> val;
            temp = temp -> next;
        }
        for(int i = 0;i<cnt;i++)
        {
            while(!st.empty() && ans[st.top()] < ans[i])
            {
                ans[st.top()] = ans[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            ans[st.top()] = 0;
            st.pop();
        }
        return ans;
    }
};