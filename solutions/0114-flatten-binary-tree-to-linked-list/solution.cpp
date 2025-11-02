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
    void flatten(TreeNode* root) 
    {
        if(!root)   return;
        stack<TreeNode*> q;
        q.push(root);
        TreeNode *ans = new TreeNode(0);
        TreeNode *temp = ans;
        while(!q.empty())
        {
            TreeNode *out = q.top();
            q.pop();
            temp -> right = out;
            temp -> left = NULL;
            temp = out;
            if(out -> right)
                q.push(out -> right);
            if(out -> left)
                q.push(out -> left);
        }
        root = ans -> right;
    }
};
