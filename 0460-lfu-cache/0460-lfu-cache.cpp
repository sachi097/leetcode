class LFUCache {
public:
    unordered_map<int, list<vector<int>>::iterator> cacheMap;
    map<int, list<vector<int>>> counterMap;
    int capacity;
    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    void makeMostRecentlyUsed(int key, int value){
        vector<int> &vec = *(cacheMap[key]);
        int counter = vec[2];
        counterMap[counter].erase(cacheMap[key]);
        if(counterMap[counter].empty()){
            counterMap.erase(counter);
        }
        ++counter;
        counterMap[counter].push_front({key, value, counter});
        cacheMap[key] = counterMap[counter].begin();
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()){
            return -1;
        }
        int value = (*cacheMap[key])[1];
        makeMostRecentlyUsed(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key) != cacheMap.end()){
            makeMostRecentlyUsed(key, value);
        }
        else if(capacity > 0){
            counterMap[1].push_front({key, value, 1});
            cacheMap[key] = counterMap[1].begin();
            capacity--;
        }
        else{
            list<vector<int>> &dll = counterMap.begin()->second;
            int counter = dll.back()[2];
            int key_to_delete = dll.back()[0];
            dll.pop_back();
            if(dll.empty()){
                counterMap.erase(counter);
            }
            cacheMap.erase(key_to_delete);

            counterMap[1].push_front({key, value, 1});
            cacheMap[key] = counterMap[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */