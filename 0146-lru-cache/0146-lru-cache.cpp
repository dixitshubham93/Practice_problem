class LRUCache {
public:

    list<int> l;
    unordered_map<int, list<int>::iterator> mp;
    unordered_map<int,int> keyvalue;

    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {

        if(keyvalue.count(key)==0)
            return -1;

        l.erase(mp[key]);
        l.push_front(key);
        mp[key] = l.begin();

        return keyvalue[key];
    }
    
    void put(int key, int value) {

        if(keyvalue.count(key)){

            l.erase(mp[key]);
            l.push_front(key);
            mp[key] = l.begin();
            keyvalue[key] = value;
            return;
        }

        if(l.size() == capacity){

            int old = l.back();

            l.pop_back();
            mp.erase(old);
            keyvalue.erase(old);
        }

        l.push_front(key);
        mp[key] = l.begin();
        keyvalue[key] = value;
    }
};
