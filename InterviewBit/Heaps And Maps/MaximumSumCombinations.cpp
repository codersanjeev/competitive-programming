vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> ans;
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> seen;
    pq.push({A.back() + B.back(), {A.size() - 1, B.size() - 1}});
    seen.insert({A.size() - 1, B.size() - 1});
    while (C--) {
        auto curr = pq.top();
        pq.pop();
        ans.push_back(curr.first);
        int i = curr.second.first;
        int j = curr.second.second;
        int sum = A[i - 1] + B[j];
        pair<int, int> nextIndexes = {i - 1, j};
        if (seen.count(nextIndexes) == 0) {
            pq.push({sum, nextIndexes});
            seen.insert(nextIndexes);
        }
        sum = A[i] + B[j - 1];
        nextIndexes = {i, j - 1};
        if (seen.count(nextIndexes) == 0) {
            pq.push({sum, nextIndexes});
            seen.insert(nextIndexes);
        }
    }
    return ans;
}