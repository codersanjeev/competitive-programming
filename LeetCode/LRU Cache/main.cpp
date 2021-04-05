class LRUCache {
  private:
	int _capacity;
	unordered_map<int, list<pair<int, int>>::iterator> _cache;
	list<pair<int, int>> _lru;
  public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
		auto it = _cache.find(key);
		if (it == _cache.end()) {
			return -1;
		}
		_lru.splice(_lru.begin(), _lru, it->second);
		return it->second->second;
	}

	void put(int key, int value) {
		auto it = _cache.find(key);
		if (it != _cache.end()) {
			_lru.erase(it->second);
		}
		_lru.push_front({key, value});
		_cache[key] = _lru.begin();
		if (_cache.size() > _capacity) {
			int keyRemoved = _lru.rbegin()->first;
			_lru.pop_back();
			_cache.erase(keyRemoved);
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */