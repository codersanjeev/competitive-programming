class MRUQueue {
   public:
    MRUQueue(int n) {
        for (int i = 1; i <= n; i++) {
            q.push_back(i);
        }
    }

    int fetch(int k) {
        auto it = q.begin();
        advance(it, k - 1);
        q.splice(q.end(), q, it);
        it = q.end();
        it--;
        return *it;
    }

   private:
    list<int> q;
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */