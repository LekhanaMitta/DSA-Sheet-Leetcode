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
    bool yesTree(TreeNode *p, TreeNode *q)
    {
        if(!p && !q)    return true;
        if((p && !q) || (!p && q) || (p -> val != q -> val))  return false;
        return (yesTree(p -> left, q -> left) && yesTree(p -> right, q -> right));
    }
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if((p && !q) || (!p && q))  return false;
        return yesTree(p, q); 
    }
};
