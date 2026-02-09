// Last updated: 2/9/2026, 1:27:22 PM
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
    TreeNode* buildTree(vector<int> &preorder, int left, int right)
    {
        if(left > right || left == -1)    return NULL;
        int val = preorder[left];
        int mn = -1;
        for(int i=left;i<=right;i++)
        {
            if(preorder[i] > val)
            {
                mn = i;
                break;
            }
        }
        cout << val << " - " << mn << endl;
        TreeNode* root = new TreeNode(val);
        if(mn == -1)
        {
            root -> left = buildTree(preorder, left+1, right);
            root -> right = NULL;
            return root;
        }
        root -> left = buildTree(preorder, left+1, mn - 1);
        root -> right = buildTree(preorder, mn, right);
        return root;
    }
    int idx = 0;
    TreeNode* buildTree(vector<int>& preorder, int limit)
    {
        if(idx == preorder.size() || preorder[idx] > limit)   return NULL;
        TreeNode* root = new TreeNode(preorder[idx++]);
        root -> left = buildTree(preorder, root -> val);
        root -> right = buildTree(preorder, limit);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        // return buildTree(preorder, 0, preorder.size()-1);    
        return buildTree(preorder, INT_MAX);
    }
};