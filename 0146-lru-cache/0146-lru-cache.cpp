class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator, int>> cacheMap;
    list<int> dll;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;    
    }

    void makeRecentlyUsed(int key){
        dll.erase(cacheMap[key].first);
        dll.push_front(key);
        cacheMap[key].first = dll.begin();
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()){
            return -1;
        }
        makeRecentlyUsed(key);
        return cacheMap[key].second;
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key) != cacheMap.end()){
            cacheMap[key].second = value;
            makeRecentlyUsed(key);
        }
        else{
            dll.push_front(key);
            cacheMap[key] = {dll.begin(), value};
            capacity--;
        }


        if(capacity < 0){
            int keyToDelete = dll.back();
            cacheMap.erase(keyToDelete);
            dll.pop_back();
            capacity++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */