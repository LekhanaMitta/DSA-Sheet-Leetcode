class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> v;
    RandomizedSet() 
    {  }
    
    bool insert(int val) 
    {
        if(m.find(val) == m.end())
        {
            v.push_back(val);
            m[val] = v.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) 
    {
        if(m.find(val) != m.end())
        {
            int idx = m[val];
            int back = v.back();
            v[idx] = back;
            m[back] = idx;
            v.pop_back();
            m.erase(val);
            return true;
        }
        return false;
        
    }
    
    int getRandom() 
    {
        int x = rand()%(v.size());    
        return v[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
