class FrontMiddleBackQueue {
  public:

	deque<int> arr;

	FrontMiddleBackQueue() {
		arr.clear();
	}

	void pushFront(int val) {
		arr.push_front(val);
	}

	void pushMiddle(int val) {
		int n = arr.size();
		int m = n / 2;
		arr.insert(arr.begin() + m, val);
	}

	void pushBack(int val) {
		arr.push_back(val);
	}

	int popFront() {
		if (arr.empty()) {
			return -1;
		}
		int ans = arr.front();
		arr.pop_front();
		return ans;
	}

	int popMiddle() {
		if (arr.empty()) {
			return -1;
		}
		int n = arr.size();
		int m = (n - 1) / 2;
		auto it = arr.begin() + m;
		int ans = *it;
		arr.erase(it);
		return ans;
	}

	int popBack() {
		if (arr.empty()) {
			return -1;
		}
		int ans = arr.back();
		arr.pop_back();
		return ans;
	}
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */