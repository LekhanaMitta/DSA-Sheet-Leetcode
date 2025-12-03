/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root || root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root -> left, p, q);
        TreeNode* r = lowestCommonAncestor(root ->right, p, q);
        if(l && r)   return root;
        return l ? l : r;
    }
};
/*
- If either of p or q is found, then return that node.
- Search left and right of the current node:
    - If both are in one side of current node, then we can get LCA using step - 1.
    - If both are in different sides then the node at which there is a split then it is LCA.
- LCA can either be in left or right based on which value is null or not.
*/
