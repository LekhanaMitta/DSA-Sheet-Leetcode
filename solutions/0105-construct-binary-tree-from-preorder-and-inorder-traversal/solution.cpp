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
    map<int, int> m;
    int idx = 0;
    TreeNode* construct(vector<int> &preorder, int left, int right)
    {
        if(left > right)
            return NULL;
        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);
        int mid = m[val];
        root -> left = construct(preorder, left, mid-1);
        root -> right = construct(preorder, mid+1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n = inorder.size();
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] = i;
        return construct(preorder, 0, n-1);
    }
};
