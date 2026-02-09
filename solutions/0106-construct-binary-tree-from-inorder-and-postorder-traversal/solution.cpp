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
    int idx = 0;
    map<int,int> m;
    TreeNode* construct(vector<int>& postorder, int start, int last)
    {
        if(start > last) return NULL;
        int val = postorder[idx--];
        TreeNode* root = new TreeNode(val);
        int mid = m[val];
        root -> right = construct(postorder, mid+1, last);
        root -> left = construct(postorder, start, mid-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n = postorder.size()-1;
        idx = n;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] = i;
        return construct(postorder, 0, n);
    }
};
