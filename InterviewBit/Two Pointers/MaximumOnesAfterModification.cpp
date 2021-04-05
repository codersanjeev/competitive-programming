int Solution::solve(vector<int> &A, int B) {
    int N = A.size(), i = 0, j = 0;
    while (j < N) {
        if (A[j] == 0) {
            B--;
        }
        if (B < 0 && A[i++] == 0) {
            B++;
        }
        j++;
    }
    return j - i;
}