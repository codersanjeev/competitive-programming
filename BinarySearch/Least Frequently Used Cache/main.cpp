class LFUCache {
   public:
    LFUCache(int capacity) {
        _capacity = capacity;
        _minimumFrequency = 0;
    }

    int get(int key) {
        if (_cache.count(key) == 0) {
            return -1;
        }
        updateFrequencyMap(key);
        return _cache[key].first;
    }

    void set(int key, int value) {
        if (_capacity <= 0) {
            return;
        }
        if (_cache.count(key) > 0) {
            updateFrequencyMap(key);
            _cache[key].first = value;
        } else {
            if (_cache.size() >= _capacity) {
                int leastFrequency = _frequencyMap[_minimumFrequency].back();
                _cache.erase(leastFrequency);
                _listIteratorMap.erase(leastFrequency);
                _frequencyMap[_minimumFrequency].pop_back();
            }
            _cache[key] = make_pair(value, 0);
            _frequencyMap[0].push_front(key);
            _listIteratorMap[key] = _frequencyMap[0].begin();
            _minimumFrequency = 0;
        }
    }

   private:
    int _capacity;
    int _minimumFrequency;

    unordered_map<int, pair<int, int>> _cache;
    unordered_map<int, list<int>> _frequencyMap;
    unordered_map<int, list<int>::iterator> _listIteratorMap;

    void updateFrequencyMap(int key) {
        int frequency = _cache[key].second++;
        _frequencyMap[frequency].erase(_listIteratorMap[key]);
        _frequencyMap[frequency + 1].push_front(key);
        _listIteratorMap[key] = _frequencyMap[frequency + 1].begin();
        if (_frequencyMap[_minimumFrequency].size() == 0) {
            _frequencyMap.erase(_minimumFrequency++);
        }
    }
};