class MinStack {
public:
    stack<pair<int, int>> st;
    int min = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) 
    {
        if(st.empty())  st.push({val, val});
        else
        {
            pair<int, int> p = st.top();
            if(val < p.second)
                st.push({val, val});
            else
                st.push({val, p.second});
        }   
    }
    
    void pop() 
    {
        if(st.empty())    return;
        else    st.pop();
    }
    
    int top() 
    {
        if(st.empty())  return -1;
        pair<int, int> p = st.top();
        return p.first;    
    }
    
    int getMin() 
    {
        if(st.empty())  return -1;
        pair<int, int> p = st.top();
        return p.second;    
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
