class BoundedBlockingQueue {
   public:
    BoundedBlockingQueue(int capacity) {
        _capacity = capacity;
    }

    void enqueue(int element) {
        unique_lock<mutex> uniqueLock(lock);
        conditionVariable.wait(uniqueLock, [&] {
            return q.size() < _capacity;
        });
        q.push(element);
        conditionVariable.notify_one();
    }

    int dequeue() {
        unique_lock<mutex> uniqueLock(lock);
        conditionVariable.wait(uniqueLock, [&] {
            return q.size() > 0;
        });
        int ans = q.front();
        q.pop();
        conditionVariable.notify_one();
        return ans;
    }

    int size() {
        return q.size();
    }

   private:
    mutex lock;
    condition_variable conditionVariable;
    int _capacity;
    queue<int> q;
};