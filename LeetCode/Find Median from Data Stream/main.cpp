class MedianFinder {
  public:
	/** initialize your data structure here. */
	MedianFinder() {
	}

	void addNum(int num) {
		left.push(num);
		right.push(left.top());
		left.pop();
		if (left.size() < right.size()) {
			left.push(right.top());
			right.pop();
		}
	}

	double findMedian() {
		return left.size() > right.size() ? left.top() : ((left.top() + right.top()) * 1.0) * 0.5;
	}
  private:
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */