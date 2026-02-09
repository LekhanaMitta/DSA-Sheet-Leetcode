// Last updated: 2/9/2026, 1:27:30 PM
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
    int pre_idx = 0, post_idx = 0;
    TreeNode* build(vector<int>& preorder, vector<int>& postorder) 
    {
        TreeNode* root = new TreeNode(preorder[pre_idx++]);
        if(root -> val != postorder[post_idx])
            root -> left = build(preorder, postorder);
        if(root -> val != postorder[post_idx])
            root -> right = build(preorder, postorder);
        post_idx++;
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        if(preorder.empty())    return NULL;
        return build(preorder, postorder);    
    }
};