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
    TreeNode *prev = NULL, *first = NULL, *second = NULL;
    void dfs(TreeNode* curr)
    {
        if(!curr)   return;
        dfs(curr -> left);
        if(prev && prev -> val > curr -> val)
        {
            if(!first)  
                first = prev;
            second = curr;
            cout << curr -> val << " ";
        }
        prev = curr;
        dfs(curr -> right);
    }
    void recoverTree(TreeNode* root) 
    {
        dfs(root);
        if(first && second)
        {
            int temp = first -> val;
            first -> val = second -> val;
            second -> val = temp; 
        }   
    }
};
