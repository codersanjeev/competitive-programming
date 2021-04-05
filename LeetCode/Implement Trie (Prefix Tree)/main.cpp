class TrieNode {
  public:
	TrieNode() {
		children.resize(26, nullptr);
	}

	bool isEnding = false;
	vector<TrieNode *> children;
};

class Trie {
  public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode *temp = root;
		for (const auto &ch : word) {
			if (temp->children[ch - 'a'] == nullptr) {
				temp->children[ch - 'a'] = new TrieNode();
			}
			temp = temp->children[ch - 'a'];
		}
		temp->isEnding = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode *temp = root;
		for (const auto &ch : word) {
			if (temp->children[ch - 'a'] == nullptr) {
				return false;
			}
			temp = temp->children[ch - 'a'];
		}
		return temp->isEnding == true;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode *temp = root;
		for (const auto &ch : prefix) {
			if (temp->children[ch - 'a'] == nullptr) {
				return false;
			}
			temp = temp->children[ch - 'a'];
		}
		return true;
	}
  private:
	TrieNode *root = nullptr;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */