// Last updated: 2/9/2026, 1:27:49 PM
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
    map<int,int> m;
    bool findTarget(TreeNode* root, int k) 
    {
        if(root)
        {
            if(m.find(k-root->val) != m.end())  return true;
            m[root->val]++;
        }
        else
            return false;
        return (findTarget(root -> left, k) || findTarget(root->right,k));
        

    }
};