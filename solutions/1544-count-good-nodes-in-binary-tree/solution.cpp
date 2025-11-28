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
    int cnt = 0;
    void findNodes(TreeNode* root, int mx)
    {
        if(!root)   return;
        if(root && root -> val >= mx)
        {
            cnt++;
            mx = max(mx, root -> val);
        }
        findNodes(root -> left, mx);
        findNodes(root -> right, mx);
        
    }
    int goodNodes(TreeNode* root) 
    {
        if(!root)   return 0;
        findNodes(root, root -> val);  
        return cnt;  
    }
};
