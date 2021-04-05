class LRUCache {
   public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        auto it = _hash.find(key);
        if (it == _hash.end()) {
            return -1;
        }
        _lru.splice(_lru.begin(), _lru, it->second);
        return it->second->second;
    }

    void set(int key, int val) {
        auto it = _hash.find(key);
        if (it != _hash.end()) {
            _lru.erase(it->second);
        }
        _lru.push_front(make_pair(key, val));
        _hash[key] = _lru.begin();
        if (_hash.size() > _capacity) {
            int keyToBeRemoved = _lru.rbegin()->first;
            _lru.pop_back();
            _hash.erase(keyToBeRemoved);
        }
    }

   private:
    int _capacity;
    list<pair<int, int>> _lru;
    unordered_map<int, list<pair<int, int>>::iterator> _hash;
};