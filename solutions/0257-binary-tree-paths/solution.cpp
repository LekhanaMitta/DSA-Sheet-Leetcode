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
    vector<string> ans;
    void getPath(TreeNode* root, string path)
    {
        if(path != "")
            path += "->";
        path += to_string(root->val);
        if(!root->left && !root->right)
        {
            ans.push_back(path);
            return;
        }
        if(root -> left)
            getPath(root->left, path);
        if(root -> right)
            getPath(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if(!root)   return {};
        getPath(root, "");
        return ans;    
    }
};
