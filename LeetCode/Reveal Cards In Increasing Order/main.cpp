class Solution {
  public:
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		sort(deck.rbegin(), deck.rend());
		deque<int> q;
		q.push_back(deck[0]);
		int n = deck.size();
		for (int i = 1; i < n; i++) {
			q.push_front(q.back());
			q.pop_back();
			q.push_front(deck[i]);
		}
		return vector<int>(q.begin(), q.end());
	}
};