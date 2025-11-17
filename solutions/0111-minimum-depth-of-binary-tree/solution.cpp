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
    void depth(TreeNode* root, int level)
    {
        if(!root)   return;
        if(root && root -> left == NULL && root -> right == NULL)
            mn = min(mn, level);
        if(root -> left)    depth(root->left, level+1);
        if(root -> right)   depth(root->right, level+1);
    }
    int minDepth(TreeNode* root) 
    {
        if(!root)   return 0;
        depth(root, 1);
        return mn;    
    }
};
