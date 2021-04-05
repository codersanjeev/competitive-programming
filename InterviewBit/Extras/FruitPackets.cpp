int Solution::solve(int A, int B, int C) {
    int less = std::min(A, B);
    int more = std::max(A, B);
    if (C >= less)
        return less;
    int count = C;
    less -= C;
    more -= C;
    auto diff = std::min(more - less, less);
    more -= 2 * diff;
    less -= diff;
    count += diff;
    count += (2 * less) / 3 ;
    return count;
}
