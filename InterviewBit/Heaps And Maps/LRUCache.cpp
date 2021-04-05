#include<bits/stdc++.h>

// max len of LRU cache
int len;
// MRU --- LRU
list<int> lru;
// key -> iterator
unordered_map<int, list<int>::iterator> mp;
// key -> value
unordered_map<int, int> cache;


void evict() {
	mp.erase(lru.back());
	cache.erase(lru.back());
	lru.pop_back();
}

void updateLRU(int key) {
	if (cache.count(key) != 0) {
		lru.erase(mp[key]);
	}
	lru.push_front(key);
	mp[key] = lru.begin();
}

LRUCache::LRUCache(int capacity) {
	len = capacity;
	lru.clear();
	mp.clear();
	cache.clear();
}

int LRUCache::get(int key) {
	if (cache.count(key) == 0) {
		return -1;
	}
	updateLRU(key);
	return cache[key];
}

void LRUCache::set(int key, int value) {
	if (cache.size() == len && cache.count(key) == 0) {
		evict();
	}
	updateLRU(key);
	cache[key] = value;
}

