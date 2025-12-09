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
    TreeNode* node, *temp;
    void flatten(TreeNode* root) 
    {
        if(!root)   return;
        TreeNode* temp = new TreeNode(0);
        node = temp;
        stack<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* tree = q.top(); q.pop();
            node -> right = tree;
            node -> left = NULL;
            node = node -> right;
            if(tree -> right)   q.push(tree -> right);
            if(tree -> left)    q.push(tree -> left);
        }
        root = temp -> right;
    }
};
