// Last updated: 2/9/2026, 1:28:08 PM
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for(int i=0;i<n*2;i++)
        {
            while(!st.empty() && nums[st.top()] < nums[i%n])
            {
                ans[st.top()] = nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }    
        return ans;
    }
};