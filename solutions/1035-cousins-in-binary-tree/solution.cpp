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
    int height(TreeNode* root, int node, int h)
    {
        if(!root)   return 0;
        if(root -> val == node) return h;
        int left = height(root->left, node, h+1);
        if(left != 0)   return left;
        return height(root -> right, node, h+1);
    }
    bool sameParent(TreeNode* root, int x, int y)
    {
        if(!root)   return false;
        if(root -> left && root -> right)
        {
            if((root->left->val == x && root->right->val == y) || (root->left->val == y && root->right->val == x))
                return true;
        }
        return sameParent(root -> left, x, y) || sameParent(root -> right, x, y);
    }
    bool isCousins(TreeNode* root, int x, int y) 
    {
        return height(root, x, 0) == height(root, y, 0) && !sameParent(root, x, y);
    }
};
/*
*/
