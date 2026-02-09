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
    vector<TreeNode*> ans;
    vector<TreeNode*> build(int start, int end)
    {
        if(start > end) return {NULL};
        vector<TreeNode*> curr;
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> left = build(start, i-1);
            vector<TreeNode*> right = build(i+1, end);
            for(TreeNode* l : left)
            {
                for(TreeNode* r: right)
                {
                    TreeNode* node = new TreeNode(i);
                    node -> left = l;
                    node -> right = r;
                    curr.push_back(node);
                }
            }
        }
        return curr;
    }
    vector<TreeNode*> generateTrees(int n) 
    {
        return build(1, n);    
    }
};
