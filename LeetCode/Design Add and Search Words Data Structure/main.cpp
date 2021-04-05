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
	bool search(string &word, TrieNode *temp, int index) {
		if (index == word.size()) {
			return temp->isEnding;
		}
		if (word[index] != '.') {
			temp = temp->children[word[index] - 'a'];
			return temp == nullptr ? false : search(word, temp, index + 1);
		}
		for (int i = 0; i < 26; i++) {
			if (temp->children[i] != nullptr && search(word, temp->children[i], index + 1)) {
				return true;
			}
		}
		return false;
	}

	TrieNode *root = nullptr;
};

class WordDictionary {
  public:
	/** Initialize your data structure here. */

	Trie *trie;

	WordDictionary() {
		trie = new Trie();
	}

	void addWord(string word) {
		trie->insert(word);
	}

	bool search(string word) {
		return trie->search(word, trie->root, 0);
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */