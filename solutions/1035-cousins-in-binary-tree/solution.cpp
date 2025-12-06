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
    int p;
    // void dfs(TreeNode* root, int x)
    // {
    //     if(!root)   return;
    //     if((root -> left && root -> left -> val == x )|| (root -> right && root -> right -> val == x)) 
    //     {
    //             p = root -> val;
    //             return;
    //     }
    //     dfs(root -> left, x);
    //     dfs(root -> right, x);
    //     h++;
    // }
    int dfs(TreeNode* root, int x, int h)
    {
        if(!root)   return 0;
        if((root -> left && root -> left -> val == x )|| (root -> right && root -> right -> val == x))
        {
            p = root -> val;
            return h+1;
        }
        int left = dfs(root -> left, x, h+1);
        if(left != 0)   return left;
        int right = dfs(root -> right, x, h+1);
        if(right != 0)  return right;
        return 0;
    }

    bool isCousins(TreeNode* root, int x, int y) 
    {
        int h1 = dfs(root, x, 1);
        int p1 = p;
        cout << h1 << " " << p1 << endl;
        int h2 = dfs(root, y, 1);
        int p2 = p;
        cout << h2 << " " << p2 << endl;
        if(h1 == h2)
        {
            if(p1 == p2)    return false;
            else    return true;
        }
        return false;
    }
};
