struct TrieNode {
	bool isLeaf;
	TrieNode *child[26];
};

TrieNode *getTrieNode() {
	TrieNode *node = new TrieNode();
	for (int i = 0; i < 26; i++) {
		node->child[i] = NULL;
	}
	node->isLeaf = false;
	return node;
}

void insertWord(TrieNode *node, string &word) {
	for (auto ch : word) {
		int index = ch - 'a';
		if (node->child[index] == NULL) {
			node->child[index] = getTrieNode();
		}
		node = node->child[index];
	}
	node->isLeaf = true;
}

bool searchWord(TrieNode *node, string &word) {
	for (auto ch : word) {
		int index = ch - 'a';
		if (node->child[index] == NULL) {
			return false;
		}
		node = node->child[index];
	}
	return node->isLeaf;
}

void convertWord(string &word) {
	for (auto &ch : word) {
		if (ch == '_') {
			ch = ' ';
		}
	}
}

vector<int> Solution::solve(string A, vector<string> &B) {
	TrieNode *root = getTrieNode();
	convertWord(A);
	string word;
	stringstream ss;
	ss << A;
	while (ss >> word) {
		insertWord(root, word);
	}
	vector<pair<int, int>> arr;
	for (int i = 0; i < B.size(); i++) {
		string x = B[i];
		convertWord(x);
		ss.clear();
		ss << x;
		int count = 0;
		while (ss >> word) {
			if (searchWord(root, word)) {
				count++;
			}
		}
		arr.push_back({count, i});
	}
	sort(arr.begin(), arr.end(), [](const pair<int, int> &X, const pair<int, int> &Y) {
		if (X.first == Y.first) {
			return X.second < Y.second;
		}
		return X.first > Y.first;
	});
	vector<int> ans;
	for (auto ele : arr) {
		ans.push_back(ele.second);
	}
	return ans;
}
