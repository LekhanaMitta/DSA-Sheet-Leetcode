// Last updated: 2/9/2026, 1:27:35 PM
class MyHashMap {
public:
vector<int> vec;
    MyHashMap() 
    {
        vec.resize(1000001);
        fill(vec.begin(), vec.end(), -1);
    }
    
    void put(int key, int value) 
    {
        vec[key] = value;
    }
    
    int get(int key) 
    {
        return vec[key];    
    }
    
    void remove(int key) 
    {
        vec[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */