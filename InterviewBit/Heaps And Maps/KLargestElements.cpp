vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int> pq(A.begin(), A.end());
    vector<int> ans;
    while (B--) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}