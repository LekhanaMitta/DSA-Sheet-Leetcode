class RandomizedCollection {
public:
    map<int, unordered_set<int>> m;
    vector<int> vec;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) 
    {
        vec.push_back(val);
        m[val].insert(vec.size()-1);
        if(m[val].size() > 1)   return false;
        return true;
    }
    
    bool remove(int val) 
    {
        if(m.find(val)==m.end() || m[val].empty())   return false;
        int x = *m[val].begin();
        int temp = vec.back();
        m[val].erase(x);
        if (x != vec.size() - 1) 
        {
            vec[x] = temp;        
            m[temp].erase(vec.size() - 1);
            m[temp].insert(x);
        } else 
            m[temp].erase(vec.size() - 1);
        vec.pop_back();
        if(m[val].empty())  m.erase(val);
        return true;
    }
    
    int getRandom() 
    {
        if(vec.size() <= 0) return -1;
        int r = rand()%vec.size();
        return vec[r];    
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
