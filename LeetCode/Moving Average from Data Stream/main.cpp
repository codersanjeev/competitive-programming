class MovingAverage {
   public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        _size = size;
    }

    double next(int val) {
        if (q.size() == _size) {
            int rem = q.front();
            q.pop();
            _sum -= rem;
        }
        q.push(val);
        _sum += val;
        return (_sum * 1.0) / q.size();
    }

   private:
    int _size, _sum = 0;
    queue<int> q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */