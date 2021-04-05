vector<int> solve(int n, int lower, int upper) {
    deque<int> q;
    int num = upper;
    for (int i = 0; i < n - 1; i++) {
        if (num < lower) {
            break;
        }
        q.push_back(num--);
    }
    int right = q.size();
    num = upper - 1;
    for (int i = 0; i < n - right; i++) {
        if (num < lower) {
            break;
        }
        q.push_front(num--);
    }
    if (q.size() != n) {
        return {};
    }
    return vector<int>(q.begin(), q.end());
}