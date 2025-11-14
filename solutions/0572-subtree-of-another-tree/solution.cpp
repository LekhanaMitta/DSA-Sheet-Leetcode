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
    // bool found = false;
    bool found(TreeNode *p, TreeNode *q)
    {
        if(!p && !q)    return true;
        if((p && !q) || (q && !p))    return false;
        cout << p-> val << " " << q -> val << endl;
        if((p -> val != q -> val))  return false;
        return (found(p -> left, q -> left) && found(p -> right, q -> right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if((root && !subRoot) || (!root && subRoot))    return false;
        if(found(root, subRoot))    return true;
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};
