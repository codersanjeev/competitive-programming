class RecentCounter {
  public:

	deque<int> arr;

	RecentCounter() {
		arr.clear();
	}

	int ping(int t) {
		arr.push_front(t);
		while (arr.back() < t - 3000) {
			arr.pop_back();
		}
		return arr.size();
	}
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */