class FreqStack {
   public:
    FreqStack() {
        maxFrequency = 0;
        frequency.clear();
        st.clear();
    }

    void push(int x) {
        frequency[x]++;
        maxFrequency = max(maxFrequency, frequency[x]);
        st[frequency[x]].push(x);
    }

    int pop() {
        int ans = st[maxFrequency].top();
        st[maxFrequency].pop();
        frequency[ans]--;
        if (st[maxFrequency].empty()) {
            maxFrequency--;
        }
        return ans;
    }

   private:
    unordered_map<int, int> frequency;
    unordered_map<int, stack<int>> st;
    int maxFrequency;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */