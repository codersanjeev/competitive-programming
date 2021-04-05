bool good(const vector<int> &piles, int speed, int time) {
    int curr = 0;
    for (const auto &ele : piles) {
        curr += ele / speed;
        if (ele % speed > 0) curr++;
    }
    return curr <= time;
}

int solve(vector<int> &piles, int h) {
    int lo = 1, hi = 1e9, ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (good(piles, mid, h)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}