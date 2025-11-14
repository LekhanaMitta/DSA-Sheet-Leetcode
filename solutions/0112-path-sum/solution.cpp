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
    bool calc(TreeNode* root, int target, int sum)
    {
        if(!root)   return false;
        if(root)
            sum += root -> val;
        if(!root -> left && !root -> right)
        {
            if(target == sum)   return true;
            return false;
        }
        return calc(root -> left, target, sum) || calc(root -> right, target, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root)   return false;
        return calc(root, targetSum, 0);
    }
};
