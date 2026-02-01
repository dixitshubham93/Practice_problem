class LFUCache {
public:
    map<int , list<tuple<int , int , int>>> freq;
    unordered_map<int , list<tuple<int ,int , int>>::iterator> mp;

    int capacity;
    int size = 0;
    int minFreq = 1;

    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mp.count(key) == 0) return -1;

        auto it = mp[key];
        int f = get<2>(*it);
        int value = get<1>(*it);

        freq[f].erase(it);
        if (freq[f].empty() && f == minFreq)
            minFreq++;

        freq[f + 1].push_front({key, value, f + 1});
        mp[key] = freq[f + 1].begin();

        return value;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            // update existing key
            get(key);                       // increase frequency
            get<1>(*mp[key]) = value;       // update value
            return;
        }

        // eviction
        if (size == capacity) {
            auto it = freq[minFreq].back();
            mp.erase(get<0>(it));
            freq[minFreq].pop_back();
            size--;
        }

        // insert new key
        freq[1].push_front({key, value, 1});
        mp[key] = freq[1].begin();
        minFreq = 1;
        size++;
    }
};
