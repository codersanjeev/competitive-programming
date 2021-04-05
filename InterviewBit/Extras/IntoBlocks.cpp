int Solution::solve(vector<int> &A) {
    int i = 0, j = 0, len = A.size(), difficulty = 0, max_lim = *max_element(A.begin(), A.end()) + 1, end = 0, diff_count = 0, max_count = 0;
    vector<int> last_pos(max_lim), freq(max_lim);
    for (i = 0; i < len; i++)
        last_pos[A[i]] = i;
    for (i = 0; i < len; i++) {
        if (end < i) {
            difficulty += diff_count - max_count;
            diff_count = max_count = 0;
            end = last_pos[A[i]];
        }
        else if (end < last_pos[A[i]])
            end = last_pos[A[i]];
        freq[A[i]]++;
        max_count = max(max_count, freq[A[i]]);
        diff_count++;
    }
    difficulty += diff_count - max_count;;
    return difficulty;
}
