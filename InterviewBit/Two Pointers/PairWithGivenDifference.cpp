int Solution::solve(vector<int> &A, int B) {
    // x - y = B
    // x = B + y
    unordered_set<int> seen;
    for (const auto &ele : A) {
        if (seen.count(B + ele) > 0 || seen.count(ele - B)) {
            return 1;
        }
        seen.insert(ele);
    }
    return 0;
}