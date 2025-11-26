/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*
I just missed a small logic of going from right to left.
right node becomes next for left node.
*/
class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root)   return NULL;
        // if(root -> left)
        // {
        //     root -> left -> next = root -> right;
        //     if(root -> next)
        //         root -> right -> next = root -> next -> left;
        //     connect(root -> left);
        //     connect(root -> right);
        // }    
        // return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* nxt = NULL;
            for(int i=q.size()-1;i>=0;i--)
            {
                Node* curr = q.front();
                q.pop();
                curr -> next = nxt;
                nxt = curr;
                if(curr -> right)
                    q.push(curr -> right);
                if(curr ->left)
                    q.push(curr -> left);
            }
        }
        return root;
    }
};
