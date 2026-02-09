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
    TreeNode* minNode(TreeNode* root)
    {
        TreeNode* temp = root;
        while(temp && temp -> left)
            temp = temp -> left;
        return temp;
    }
    TreeNode* maxNode(TreeNode* root)
    {
        while(root && root -> right)
            root = root -> right;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root)   return NULL;
        if(root -> val > key)
            root -> left = deleteNode(root -> left, key);
        else if(root -> val < key)
            root -> right = deleteNode(root -> right, key);
        else
        {
            if(!root -> right)
            {
                TreeNode* left_child = root -> left;
                delete root;
                return left_child;
            }
            if(!root -> left)
            {
                TreeNode* right_child = root -> right;
                delete root;
                return right_child;
            }
            // TreeNode* nxt = minNode(root->right);
            // root -> val = nxt -> val;
            // root -> right = deleteNode(root -> right, nxt -> val);
            TreeNode* nxt = maxNode(root -> left);
            root -> val = nxt -> val;
            root -> left = deleteNode(root -> left, nxt -> val);
        } 
        return root;   
    }
};
