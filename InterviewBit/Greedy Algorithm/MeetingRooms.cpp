int Solution::solve(vector<vector<int>> &A) {
    int N = A.size();
    if (N == 0) {
        return 0;
    }
    sort(A.begin(), A.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int roomsAllocated = 1;
    pq.push(A[0][1]);
    for (int i = 1; i < N; i++) {
        int currentEndingTime = pq.top();
        if (A[i][0] >= currentEndingTime) {
            pq.pop();
        } else {
            roomsAllocated++;
        }
        pq.push(A[i][1]);
    }
    return roomsAllocated;
}
