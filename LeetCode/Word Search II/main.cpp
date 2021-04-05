class TrieNode {
  public:
	char ch;
	int isEnding = false;
	string word = "";
	vector<TrieNode *> children;
	TrieNode(char ch) {
		this->ch = ch;
		children.resize(26, nullptr);
	}
};

class Trie {
  public:
	TrieNode *root;
	Trie() {
		root = new TrieNode('/');
	}

	void insertWord(const string &word) {
		TrieNode *crawler = root;
		for (const auto &ch : word) {
			if (crawler->children[ch - 'a'] == nullptr) {
				crawler->children[ch - 'a'] = new TrieNode(ch);
			}
			crawler = crawler->children[ch - 'a'];
		}
		crawler->isEnding = true;
		crawler->word = word;
	}

};

class Solution {
  public:
	vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
		Trie *trie = new Trie();
		for (const auto &word : words) {
			trie->insertWord(word);
		}
		int n = board.size(), m = board[0].size();
		vector<string> ans;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dfs(board, trie->root, i, j, n, m, ans);
			}
		}
		return ans;
	}

  private:

	vector<pair<int, int>> delta = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

	void dfs(vector<vector<char>> &board, TrieNode *trie, int i, int j, int n, int m, vector<string> &ans) {
		if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '$' || trie->children[board[i][j] - 'a'] == nullptr) {
			return;
		}
		trie = trie->children[board[i][j] - 'a'];
		if (trie->isEnding) {
			ans.push_back(trie->word);
			trie->isEnding = false;
		}
		char temp = board[i][j];
		board[i][j] = '$';
		for (int k = 0; k < 4; k++) {
			dfs(board, trie, i + delta[k].first, j + delta[k].second, n, m, ans);
		}
		board[i][j] = temp;
	}
};