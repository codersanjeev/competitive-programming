class MaxStack {
   public:
    /** initialize your data structure here. */
    MaxStack() {
    }

    void push(int x) {
        int mx = maxStack.empty() ? x : maxStack.top();
        maxStack.push(max(mx, x));
        mainStack.push(x);
    }

    int pop() {
        int ans = mainStack.top();
        mainStack.pop();
        maxStack.pop();
        return ans;
    }

    int top() {
        return mainStack.top();
    }

    int peekMax() {
        return maxStack.top();
    }

    int popMax() {
        int ans = peekMax();
        stack<int> buffer;
        while (top() != ans) {
            buffer.push(pop());
        }
        pop();
        while (!buffer.empty()) {
            push(buffer.top());
            buffer.pop();
        }
        return ans;
    }

   private:
    stack<int> mainStack, maxStack;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */