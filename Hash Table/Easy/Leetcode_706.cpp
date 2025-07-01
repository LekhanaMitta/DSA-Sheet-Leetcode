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
