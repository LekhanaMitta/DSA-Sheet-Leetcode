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
    int mn = INT_MAX;
    TreeNode *node = NULL;
    void dfs(TreeNode* root)
    {
        if(root -> left)    dfs(root -> left);
        if(node)
            mn = min(mn, abs(root->val - node->val));
        node = root;
        if(root -> right)   dfs(root -> right);
    }
    int getMinimumDifference(TreeNode* root) 
    {
        dfs(root);
        return mn;    
    }
};
