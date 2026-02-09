// Last updated: 2/9/2026, 1:28:08 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, int> m;
    int dfs(TreeNode* root, int sum)
    {
        if(!root)
            return 0;
        sum += root -> val;
        sum += dfs(root -> left, 0);
        sum += dfs(root -> right, 0);
        m[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        if(!root)   return {};
        dfs(root, 0);
        int mx = 0;
        vector<int> v;
        for(auto it : m)
            mx = max(mx, it.second);
        for(auto it : m)
            if(it.second == mx)
                v.push_back(it.first);
        return v;
    }
};