class Node{
public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
class MyLinkedList {
public:
    Node *head;
    Node *tail;
    int sz;
    MyLinkedList() 
    {
        head = tail = NULL;
        sz = 0;
    }
    
    int get(int index) 
    {
        if(index < 0 || index >= sz) return -1;
        else if(index == 0)  return head -> val;
        else if(index == sz - 1)    return tail -> val;
        else
        {
            Node *temp = head;
            for(int i = 1;i <= index;i++)
                temp = temp -> next;
            return temp -> val;
        }
    }
    
    void addAtHead(int val) 
    {
        Node *temp = new Node(val);
        cout << val << " ";
        if(sz == 0) head = tail = temp;
        else
        {
            temp -> next = head;
            head = temp; 
        }   
        sz++;
    }
    
    void addAtTail(int val) 
    {
        Node *temp = new Node(val);
        cout << val << " ";
        if(sz == 0) head = tail = temp;
        else
        {
            tail -> next = temp;
            tail = temp;
        }
        sz++;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index < 0 || index > sz)   return;
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        if(index == sz)
        {
            addAtTail(val);
            return;
        }
        
            Node *temp = head;
            Node *temp1 = new Node(val);
            cout << val << " ";
            for(int i = 1;i <= index - 1;i++)
            {
                temp = temp -> next;
                cout << temp  -> val << " --- " << endl;
            }
            temp1 -> next = temp -> next;
            temp -> next = temp1;
            sz++;
        
    }
    
    void deleteAtIndex(int index) 
    {
        if(index < 0 || index >= sz)
            return;
        else if(index == 0)
            head = head -> next;
        else
        {
            Node *temp = head;
            for(int i = 1;i <= index - 1;i++)
                temp = temp -> next;
            if(temp -> next -> next == NULL)
            {
                tail = temp;
                temp -> next = NULL;
            }
            else
            {
                Node *temp1 = temp -> next;
                temp -> next = temp1 -> next;
                temp1 -> next = NULL; 
            }
        }
        sz--;    
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
