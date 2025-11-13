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
    int sum = 0;
    void leftSum(TreeNode *root, bool isLeft)
    {
        if(!root)   return;
        if(root -> left == NULL && root -> right == NULL && isLeft)
            sum += root -> val;
        if(root -> left)
            leftSum(root -> left, true);
        if(root -> right)
            leftSum(root -> right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(!root)   return 0;
        leftSum(root, false);
        return sum;    
    }
};
