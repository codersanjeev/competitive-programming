class HashTable {
  private:
	static const int hashGroups = 1024;
	list<pair<int, int>> table[hashGroups];
  public:
	HashTable() {
		for (int i = 0; i < hashGroups; i++) {
			table[i].clear();
		}
	}

	int hash(int key) {
		return key % hashGroups;
	}

	void put(int key, int val) {
		int hashValue = hash(key);
		auto &cell = table[hashValue];
		auto it = cell.begin();
		bool keyExists = false;
		while (it != cell.end()) {
			if (it->first == key) {
				keyExists = true;
				it->second = val;
				break;
			}
			it++;
		}
		if (keyExists == false) {
			cell.push_back({key, val});
		}
	}

	int get(int key) {
		int hashValue = hash(key);
		auto &cell = table[hashValue];
		auto it = cell.begin();
		bool keyExists = false;
		while (it != cell.end()) {
			if (it->first == key) {
				keyExists = true;
				return it->second;
			}
			it++;
		}
		return -1;
	}

	void remove(int key) {
		int hashValue = hash(key);
		auto &cell = table[hashValue];
		auto it = cell.begin();
		bool keyExists = false;
		while (it != cell.end()) {
			if (it->first == key) {
				keyExists = true;
				it = cell.erase(it);
				break;
			}
			it++;
		}
	}
};