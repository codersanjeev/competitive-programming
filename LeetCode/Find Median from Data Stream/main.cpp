class MedianFinder {
   private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

   public:
    MedianFinder() {}

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
        if (left.size() > right.size()) {
            return left.top();
        } else {
            return ((left.top() + right.top()) * 1.0) * 0.5;
        }
    }
};