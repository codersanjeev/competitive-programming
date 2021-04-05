class MinimumStack {
   public:
    MinimumStack() {
    }

    void append(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            int curr = st.top().second;
            if (val < curr) {
                curr = val;
            }
            st.push({val, curr});
        }
    }

    int peek() {
        return st.empty() ? -1 : st.top().first;
    }

    int min() {
        return st.empty() ? -1 : st.top().second;
    }

    int pop() {
        if (st.empty()) {
            return -1;
        } else {
            int ans = st.top().first;
            st.pop();
            return ans;
        }
    }

   private:
    stack<pair<int, int>> st;
};