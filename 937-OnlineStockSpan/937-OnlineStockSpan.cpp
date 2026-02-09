// Last updated: 2/9/2026, 1:27:30 PM
class StockSpanner {
public:
stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) 
    {
        int days = 1;
        while(!st.empty() && st.top().first <= price)
        {
            
            days += st.top().second;
            // cout << st.top().first <<" <= "<<price<< "-->"<<st.top().second <<" "<<days<<endl;
            cout << "pop : " << st.top().first << "-->"<<st.top().second<<endl;
            st.pop();
        }   
        cout << price << " " << days << endl; 
        st.push({price, days});
        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */