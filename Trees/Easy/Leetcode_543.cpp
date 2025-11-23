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
int mx = INT_MIN;
    int height(TreeNode* root)
    {
        if(!root)   return 0;
        else if(root && !root -> left && !root -> right)
            return 1;
        else
        {
            int left = height(root -> left);
            int right = height(root -> right); 
            int h = 1 + max(left, right);
            mx = max(mx, left + right);
            return h;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(!root)   return 0;
        int h = height(root -> left) + height(root -> right);
        return max(mx, h);    
    }
};
