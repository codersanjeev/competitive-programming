const int MAX = 50002;

struct TrieNode {
	int many;
	int sons[26];
};

TrieNode trie[MAX];
int m = 1;

void addWord(string s) {
	int pos = 1;
	for (auto ch : s) {
		int index = ch - 'a';
		if (!trie[pos].sons[index]) {
			trie[pos].sons[index] = ++m;
		}
		pos = trie[pos].sons[index];
		trie[pos].many++;
	}
}

string queryWord(string word) {
	int pos = 1;
	string ans = "";
	for (auto ch : word) {
		ans += ch;
		int index = ch - 'a';
		pos = trie[pos].sons[index];
		if (trie[pos].many == 1) {
			return ans;
		}
	}
	return word;
}

vector<string> Solution::prefix(vector<string> &words) {
	memset(trie, 0, sizeof(trie));
	for (auto &word : words) {
		addWord(word);
	}
	vector<string> ans;
	for (auto &word : words) {
		ans.push_back(queryWord(word));
	}
	return ans;
}
